all: lexer

lexer: lexer.l
	flex lexer.l
	gcc lex.yy.c -o analisador_lexico

testar: all
	./analisador_lexico testes/prog1.oxi
	./analisador_lexico testes/prog2.oxi
	./analisador_lexico testes/prog3.oxi
	./analisador_lexico testes/prog4.oxi

clean:
	rm -f lex.yy.c analisador_lexico