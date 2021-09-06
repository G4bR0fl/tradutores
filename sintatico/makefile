all: compile

compile: src/lex.yy.c
	gcc-11 -g -Wall -o tradutor src/sintatico.tab.c src/lex.yy.c -ll

src/lex.yy.c: src/sintatico.tab.c
	flex -o src/lex.yy.c src/lexico.l

src/sintatico.tab.c: src/sintatico.y
	bison -d -Wcounterexamples -Wother -o src/sintatico.tab.c src/sintatico.y

clean: 
	rm -rf *.o *~ tradutor src/lex.yy.c