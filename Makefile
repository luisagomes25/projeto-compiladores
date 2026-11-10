all: oxitona

oxitona: lexer.l parser.y main.cpp ast.cpp
	bison -d parser.y
	flex lexer.l
	g++ -std=c++17 lex.yy.c parser.tab.c main.cpp ast.cpp -o oxitona

testar: all
	./oxitona testes/prog1.oxi

clean:
	rm -f lex.yy.c parser.tab.c parser.tab.h oxitona
