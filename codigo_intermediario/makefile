all: compile

compile: src/lex.yy.c
	gcc-11 -g -Wall -I lib -o tradutor src/sintatico.tab.c src/lex.yy.c src/tabela.c src/arvore.c src/pilha.c src/semantic_utils.c src/tac.c -ll

src/lex.yy.c: src/sintatico.tab.c
	flex -l -o src/lex.yy.c src/lexico.l

src/sintatico.tab.c: src/sintatico.y
	bison -d -Wall -Wcounterexamples -Wother -o src/sintatico.tab.c src/sintatico.y

clean: 
	rm -rf *.o *~ tradutor src/lex.yy.c src/sintatico.tab.c src/sintatico.tab.h
