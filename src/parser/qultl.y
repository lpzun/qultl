/*******************************************************************************
 ** Name:    	BoPP: parser
 ** Authors: 	Peizun Liu
 ** Version: 	0.5
 ** Copyright: 	It belongs to Thomas Wahl's group in CAR Lab, CCIS, NEU
 ** Create on:  Feb, 2014
 ** Modified :  Jan, 2016
 ** Decription: BoPP is a Boolean Program Parser written with C++. It aims  at
 *		parsing Boolean programs to generate a control folow graph and 
 *		the corresponding weakest preconditions (strongest postcondit-
 *              ions) for each statement when computing a preimage (postimage).
 *
 *              parser: 
 *              v0.5: adding the forward-based CFG and so on
 ******************************************************************************/
%language "C++"
%locations     // enable location tracking
%error-verbose // verbose error messages

%code requires
{
# include "helper.hh"
  using namespace qultl;
}

 // tell Bison that yyparse should take an extra parameter paide
%parse-param { qultl_helper &qh }

%define parser_class_name {qultl} // define the parser's name
%{
%}

// use Bison's %union construct to define a semantic value type for integers 
// and character pointers (strings)
%union {
  int   t_val; // token's value
  char *t_str; // token's name
  char *t_sep; // token's separator
}

/* declare tokens */
%token T_QuLTL_F "F"
%token T_QuLTL_G "G"
%token T_QuLTL_X "X"          
%token T_QuLTL_U "U"          

%token T_ADDITION "+" 	     
%token T_SUBTRACTION "-"
%token T_MULTIPLICATION "*" 	      

%token T_NEGATION "!"	     
%token T_AND "&"	     
%token T_OR "|"	     
%token T_IMPLICATION "->"	     

%token T_EQUAL "="			
%token T_NOT_EQUAL "!="			 
%token T_LESS_THAN "<"			 
%token T_GREATER_THAN ">"			
%token T_LESS_THAN_OR_EQU "<="			 
%token T_GREATER_THAN_OR_EQU ">="

%token T_COUNTING "#"

%token T_CONST_TRUE "true"
%token T_CONST_FALSE "false"

%token T_END;

%token <t_val> T_NAT
%token <t_str> T_IDEN
%token <t_sep> T_DELIM

%type <t_str> phi literal msg // value
%type <t_val> constant //

%start phi
%{
  extern int yylex(yy::qultl::semantic_type *yylval, yy::qultl::location_type* yylloc);
%}

%initial-action {
  // add filename to location info here
  @$.begin.filename = @$.end.filename = new std::string("stdin");
 }


/******************************************************************************
 * ** bison rules for QuLTL parser
 ******************************************************************************/
%%
phi: bin_phi ';' {}
;

bin_phi: una_phi {}
| bin_phi T_QuLTL_U una_phi {
  qh.parse_and_update("U");
 }
;

una_phi: prm_phi {}
| T_QuLTL_F una_phi {
   qh.parse_and_update("F");
}
| T_QuLTL_G una_phi {
   qh.parse_and_update("G");
}
| T_QuLTL_X una_phi {
   qh.parse_and_update("X");
}
;

prm_phi: '(' phi ')' {
  qh.parse_and_update("()");
 }
| msg {
}
| expr {
}
;

expr: or_expr {}
| expr T_IMPLICATION or_expr {
  qh.parse_and_update("->");
 }
;

or_expr: and_expr {}
| or_expr T_OR and_expr {
  qh.parse_and_update("|");
 }
;

and_expr: una_expr {}
| and_expr T_AND una_expr {
  qh.parse_and_update("&");
 }
;

una_expr: prm_expr {}
| T_NEGATION prm_expr {
  qh.parse_and_update("!");
 }
;

prm_expr: '(' expr ')' {
  qh.parse_and_update("()");
 }
| T_CONST_TRUE {
  qh.parse_and_update("true");
  }
| T_CONST_FALSE {
  qh.parse_and_update("false");
  }
| literal {}
;

literal: qula_expr T_EQUAL qula_expr {
  qh.parse_and_update("=");
}
| qula_expr T_NOT_EQUAL qula_expr {
  qh.parse_and_update("!=");
}
| qula_expr T_LESS_THAN qula_expr {
  qh.parse_and_update("<");
}
| qula_expr T_GREATER_THAN qula_expr {
  qh.parse_and_update(">");
}
| qula_expr T_LESS_THAN_OR_EQU qula_expr {
  qh.parse_and_update("<=");
}
| qula_expr T_GREATER_THAN_OR_EQU qula_expr {
  qh.parse_and_update(">=");
}
;

qula_expr: qula_add_expr {}
| qula_expr T_MULTIPLICATION qula_add_expr {
  qh.parse_and_update("*");
 }
;

qula_add_expr: qula_sub_expr {}
| qula_add_expr T_ADDITION qula_sub_expr {
  qh.parse_and_update("+");
 }
;

qula_sub_expr: qula_prm_expr {}
| qula_sub_expr T_SUBTRACTION qula_prm_expr {
  qh.parse_and_update("-");
 }
;

qula_prm_expr: '(' qula_expr ')' {
  qh.parse_and_update("()");
}
| T_COUNTING msg {
  qh.parse_and_update("#");
}
| '[' ']' {
}
| constant {}
;

msg: T_IDEN {
  qh.parse_and_update($1);
  free($1);
}
;

constant: T_NAT {
  qh.parse_and_update(std::to_string($1));
 }
;

%%

/*******************************************************************************
 * ** From here, 
 *         functions used in parser, defined in c++
 *
 *    Mar. 2013
 ******************************************************************************/
namespace yy {
  void qultl::error(location const &loc, const std::string& s) {
    std::cerr << "error at " << loc << ": " << s << std::endl;
  }
}
