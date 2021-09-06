int i;
float j;

int list list_reader(int n) {
    int i;
    int elem;
    float list new_list;
    new_list = NIL;
    writeln("Digite um novo elemento da lista:");
    read(elem);
    new_list = elem : new_list;
    return new_list;
}