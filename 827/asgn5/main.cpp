#include <iostream>
#include <string>

// #include "includes/symbolTable.h"
// #include "includes/ast.h"
#include "includes/poolOfNodes.h"
#include "parse.tab.h"

extern void init_scanner(FILE *);
extern void free_tok();

static FILE *
open_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
    fprintf(stderr, "Could not open file \"%s\"\n", filename);
    exit(EXIT_FAILURE);
    }
    return file;
}


int main(int argc, char * argv[]) {
    FILE *input_file = stdin;
    if (argc > 1) { /* user-supplied filename */
    input_file = open_file(argv[1]);
    }
    init_scanner(input_file);
    yydebug = 0;  /* Change to 1 if you want debugging */

    int parse_had_errors;
    try {
      parse_had_errors = yyparse();
      if (parse_had_errors) {
        fprintf(stderr,"Abnormal termination\n");
      }
      else {
          std::cout << "Program syntactically correct" << std::endl;
          PoolOfNodes::getInstance().drainThePool();
      }
    }
    catch( ... ) {
      std::cout << "opps, something wrong" << std::endl;
    }

    free_tok();
    // fclose(input_file);
    return (parse_had_errors ? EXIT_FAILURE : EXIT_SUCCESS);
}
