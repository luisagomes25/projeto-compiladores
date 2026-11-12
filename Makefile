all: oxitona oxi

oxitona: lexer.l parser.y main.cpp ast.cpp
	bison -d parser.y
	flex lexer.l
	g++ -std=c++17 -x c++ lex.yy.c parser.tab.c main.cpp ast.cpp -o oxitona

oxi: oxitona
	cp oxitona oxi

testar: all
	./oxitona testes/prog1.oxi

test: all
	sh testes/testar.sh

clean:
	rm -f lex.yy.c parser.tab.c parser.tab.h oxi oxitona
