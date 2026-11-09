all: lexer

lexer: lexer.l
	flex lexer.l
	gcc lex.yy.c -o analisador_lexico

clean:
	rm -f lex.yy.c analisador_lexico