/*******************************************************************************  
 ** Name:    	qultl: lexer
 ** Authors: 	Peizun Liu
 ** Version: 	0.4
 ** Copyright: 	It belongs to Thomas Wahl's group in CAR Lab, CCIS, NEU
 ** Date:       Oct. 2018
 ** Decription: qultl is a C++ version of QuLTL Parser. 
 ******************************************************************************/
%option noyywrap 
%option yylineno 
%{
	#include <cstdlib>      // C Standard General Utilities Library
	#include "qultl.tab.hh" // generated by bison

	/* define YY_DECL to declare the calling sequence for yylex to  
	 * match what the parser expects
	 */
	#define YY_DECL int yylex(yy::qultl::semantic_type *yylval, \
				  yy::qultl::location_type *yylloc)

	/* make location include the current token */
	#define YY_USER_ACTION yylloc->columns (yyleng);

	typedef yy::qultl::token token;
%}

%s comment

%%

%{
	/* start where previous token ended:
	 * The step() method sets the beginning of the location equal to the end, 
	 * so the location now points to the end of the previous token.
	 */
	yylloc->step ();
%}
"/*"         		{ BEGIN(comment); }
<comment>[^*\n]*        /* eat anything that's not a '*' */
<comment>"*"+[^*/\n]*   /* eat up '*'s not followed by '/'s */
<comment>\n             
<comment>"*"+"/"        { BEGIN(INITIAL); }

"//"[^\n]+\n  

"G"          { return token::T_QuLTL_G; }
"X"          { return token::T_QuLTL_X; }
"U"          { return token::T_QuLTL_U; }

"+" 	     { return token::T_ADDITION; }
"-" 	     { return token::T_SUBTRACTION; }
"*" 	     { return token::T_MULTIPLICATION; }

"!"	     { return token::T_NEGATION; }
"&"	     { return token::T_AND; }
"|"	     { return token::T_OR; }
"->"	     { return token::T_IMPLICATION; }

"="			 { return token::T_EQUAL; }
"!="			 { return token::T_NOT_EQUAL; }
"<"			 { return token::T_LESS_THAN; }
">"			 { return token::T_GREATER_THAN; }
"<="			 { return token::T_LESS_THAN_OR_EQU; }
">="			 { return token::T_GREATER_THAN_OR_EQU; }

"#"                      { return token::T_COUNTING; }

"true"                   { return token::T_CONST_TRUE; }
"false"                  { return token::T_CONST_FALSE; }

"("			 { yylval->t_str = strdup(yytext); return ('('); }
")"			 { yylval->t_str = strdup(yytext); return (')'); }
"["			 { yylval->t_str = strdup(yytext); return ('['); }
"]"			 { yylval->t_str = strdup(yytext); return (']'); }

[0-9]+ 			  { yylval->t_val = atoi(yytext);   return token::T_NAT; }
[a-zA-Z_\'][a-zA-Z0-9_$]* { yylval->t_str = strdup(yytext); return token::T_IDEN; }

[ \t\n\v\f]		 { }
. 			 { /* ignore bad characters */ }
%%
