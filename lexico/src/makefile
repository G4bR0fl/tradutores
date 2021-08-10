all: compile

compile: lex.yy.c
	gcc-11 -o tradutores lex.yy.c -ll

lex.yy.c: lexico.l
	flex lexico.l

