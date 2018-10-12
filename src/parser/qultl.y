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
# include "parser.hh"
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
}

/* declare tokens */
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

%token <t_val> T_NAT
%token <t_str> T_IDEN

%type <t_str> phi qexpr literal qula msg // value
%type <t_val> constant

%start phi
%{
  extern int yylex(yy::qultl::semantic_type *yylval, yy::qultl::location_type* yylloc);
%}

%initial-action {
  // add filename to location info here
  @$.begin.filename = @$.end.filename = new std::string("stdin");
 }


/*******************************************************************************
 * ** bison rules for BoPP parser 
 * ** BNF: prog
 *	    |-s_decllist 
 *	    |-funclist
 * 	      |-function
 *              |-funchead
 *              |-funcbody
 * 	          |-funcstmt
 * 	             |-l_declstmt
 * 	             |-initstmt
 * 	             |-labelstmt
 * 	               |-expr
 *               |-funcend
 ******************************************************************************/
%%
phi: msg {
  cout<<($1);
  free($1);
}
| T_QuLTL_U phi {
  cout<<
}
| T_QuLTL_X phi {

}
| phi T_QuLTL_U phi {

}
| '(' phi ')' {

}
;

qexpr: T_CONST_TRUE {

}
| T_CONST_FALSE {

}
| literal {

}
| T_NEGATION          qexpr {

}
| qexpr T_AND         qexpr {

}
| qexpr T_OR          qexpr {

}
| qexpr T_IMPLICATION qexpr {

}
| '(' qexpr ')' {

}
;

literal: atom brop atom {
  
}
;

brop: T_EQUAL    {

}
| T_NOT_EQUAL    {

}
| T_LESS_THAN    {

}
| T_GREATER_THAN {

}
| T_LESS_THAN_OR_EQU {

}
| T_GREATER_THAN_OR_EQU {

}
;

atom: constant {

}
| T_COUNTING msg {

}
| '[' ']' {

}
| atom T_ADDITION    atom {

}
| atom T_SUBTRACTION atom {

}
| '(' atom ')' {

}
;

msg: T_IDEN {

}
;

constant: T_NAT {
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
  void bp::error(location const &loc, const std::string& s) {
    std::cerr << "error at " << loc << ": " << s << std::endl;
  }
}
