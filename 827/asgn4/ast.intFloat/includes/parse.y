%{
#include <iostream>
#include <map>
#include <cmath>
#include "includes/ast.h"

extern int yylex();
void yyerror(const char * msg);

PoolOfNodes& pool = PoolOfNodes::getInstance();
%}

%union {
  Node* node;
  int intNumber;
  float fltNumber;
  char *id;
  int op;
}

%token CR EQ
%token<intNumber> INT
%token<fltNumber> FLOAT
%token<id> IDENT
%token<op> PLUS MINUS

%type<op> oop
%type<node> lines expr

%left MULT DIV


%%
lines   : lines expr CR
          {
            ($2)->eval()->print();
          }
        | lines IDENT EQ expr CR
          { Node* lhs = new IdentNode($2);
            $$ = new AsgBinaryNode(lhs, $4);
            pool.add(lhs);
            pool.add($$);
            delete [] $2;
          }
        | lines CR
        | { ; }
        ;

expr    : expr oop expr
          { if($2==1) {$$ = new AddBinaryNode($1, $3); pool.add($$);}
            else if($2==2) {$$ = new SubBinaryNode($1, $3);pool.add($$);}
            else {std::cout << "what??" << std::endl;}
          }
        | expr MULT expr   { $$ = new MulBinaryNode($1, $3);
                             pool.add($$);
                           }
        | expr DIV expr    { $$ = new DivBinaryNode($1, $3);
                             pool.add($$);
                           }
        | INT              { $$ = new IntLiteral($1);
                             pool.add($$);
                           }
        | FLOAT            { $$ = new FloatLiteral($1);
                             pool.add($$);
                           }
        | IDENT            { $$ = new IdentNode($1);
                             delete [] $1;
                             pool.add($$);
                           }
        ;

oop     : PLUS {$$=$1;}
        | MINUS {$$=$1;}
        ;
%%
void yyerror(const char * msg) { std::cout << msg << std::endl; }
