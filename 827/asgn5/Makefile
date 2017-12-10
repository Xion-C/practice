CCC = g++
LEX = flex
YACC = bison
CFLAGS = -g -std=c++11 -W -Wall -Weffc++ -Wextra -pedantic -O0
LEXFLAGS = -Wno-unused -Wno-sign-compare -Wno-deprecated-register

LEXDEBUG =
YACCDEBUG = -vtd

OBJS = main.o parse.tab.o lex.yy.o symbolTable.o funcTable.o scopeControl.o ast.o poolOfNodes.o

run: $(OBJS)
	$(CCC) $(CFLAGS) -o run $(OBJS)

main.o: main.cpp includes/parse.y includes/scan.l parse.tab.c lex.yy.c
	$(CCC) $(CFLAGS) -c main.cpp

parse.tab.c: includes/parse.y
	$(YACC) $(YACCDEBUG) includes/parse.y

parse.tab.o: parse.tab.c
	$(CCC) $(CFLAGS) -c parse.tab.c

lex.yy.c: includes/scan.l parse.tab.o
	$(LEX) $(LEXDEBUG) includes/scan.l

lex.yy.o: lex.yy.c
	$(CCC) $(CFLAGS) $(LEXFLAGS) -c lex.yy.c

ast.o: includes/ast.cpp includes/ast.h includes/literal.h
	$(CCC) $(CFLAGS) -c includes/ast.cpp

symbolTable.o: includes/symbolTable.cpp includes/symbolTable.h
	$(CCC) $(CFLAGS) -c includes/symbolTable.cpp

funcTable.o: includes/funcTable.cpp includes/funcTable.h
	$(CCC) $(CFLAGS) -c includes/funcTable.cpp

scopeControl.o: includes/scopeControl.cpp includes/scopeControl.h
	$(CCC) $(CFLAGS) -c includes/scopeControl.cpp

poolOfNodes.o: includes/poolOfNodes.cpp includes/poolOfNodes.h \
  includes/node.h
	$(CCC) $(CFLAGS) -c includes/poolOfNodes.cpp

clean:
	rm -f run *.o parse.tab.c lex.yy.c
	rm -f parse.tab.h
	rm -f parse.output



# CCC = g++
# LEX = flex
# YACC = bison
# CFLAGS = -Wall -std=c++11
# LEXFLAGS = -Wno-unused -Wno-sign-compare
#
# #LEXDEBUG = -d
# LEXDEBUG =
# YACCDEBUG = -vtd
#
# OBJS = main.o parse.tab.o lex.yy.o
#
# run: $(OBJS)
# 	$(CCC) $(CFLAGS) -o run $(OBJS)
#
# main.o: main.cpp includes/parse.y includes/scan.l parse.tab.c lex.yy.c
# 	$(CCC) $(CFLAGS) -c main.cpp
#
# parse.tab.c: includes/parse.y
# 	$(YACC) $(YACCDEBUG) includes/parse.y
#
# parse.tab.o: parse.tab.c
# 	$(CCC) $(CFLAGS) -c parse.tab.c
#
# lex.yy.c: includes/scan.l parse.tab.o
# 	$(LEX) $(LEXDEBUG) includes/scan.l
#
# lex.yy.o: lex.yy.c
# 	$(CCC) $(CFLAGS) $(LEXFLAGS) -c lex.yy.c
#
# clean:
# 	rm -f run *.o parse.tab.c lex.yy.c
# 	rm -f parse.tab.h
# 	rm -f parse.output
