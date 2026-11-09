all: oxitona

oxitona: lexer.l parser.y main.cpp
	bison -d parser.y
	flex lexer.l
	g++ lex.yy.c parser.tab.c main.cpp -o oxitona

testar: all
	./oxitona testes/prog1.oxi

clean:
	rm -f lex.yy.c parser.tab.c parser.tab.h oxitona