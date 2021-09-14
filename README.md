# Tradutores

## Repositório no qual ficarão os trabalhos e laboratórios de Tradutores 2021/2

- `/`: Diretório raiz com os respectivos trabalhos da disciplina;
- `/doc`: Contém o relatório;
- `/src`: Contém o código fonte `.c`, `lexico.l` e `sintatico.y`;
- `/lib`: Contém os arquivos `.h`;
- `/tests`: Contém os arquivos teste;

## Compilação:
Para executar o respectivo trabalho em questão, é necessário entrar na pasta `lexico/` ou `sintatico/` e executar o comando:

`make all`

Isso por si só irá gerar um executável que é passível de análise pelo valgrind ou apenas executar com os arquivos testes com o seguinte comando:

- Testes: `./tradutor tests/<nome_do_arquivo.c>`;
- Verificação de memória: `valgrind ./tradutor tests/<nome_do_arquivo_correto.c>`;
