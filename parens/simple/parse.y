%{
#include <iostream>
extern int yylex();
void yyerror(const char * msg) { std::cout << msg << std::endl; }
%}
%token CR
%token LPAR
%token RPAR
%%

lines   : lines expr CR
          { std::cout << "accept" << std::endl; }
        | %empty
        ;

expr    : expr expr
        | LPAR { std::cout << "("; } expr RPAR
               { std::cout << ")"; }
        | LPAR RPAR
          { std::cout << "(*)"; }
        ;
