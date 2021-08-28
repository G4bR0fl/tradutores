all: compile

compile: src/lex.yy.c
	gcc-11 -o tradutor src/lex.yy.c -ll

src/lex.yy.c: src/lexico.l
	flex -o src/lex.yy.c src/lexico.l

clean: 
	rm -rf *.o *~ tradutor src/lex.yy.c
