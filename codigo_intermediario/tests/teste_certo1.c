float list lista;

float times_15(int a, int b){
    int c;
    c = (a * b)*15;
    return c;
}

int lt_gt(){
    int a;
    int b;
    int c;
    a = 10;
    b = 20;
    c = 30;
    if((a > b && c > a) || (a < -b)){
        return c;
    }else return 10.3;
}

float list unique_list() {
    float elem;
    float list new_list;
    new_list = NIL;
    writeln("Digite um novo elemento da lista:");
    read(elem);
    new_list = elem : new_list;
    return new_list;
}

int main(){
    int a;
    float b;
    a && b;
    int c;
    float d;
    d = lt_gt();
    c = a || b;
    writeln("Lista com head e tail");
    float list float_list;
    float_list = unique_list;
    write(-a);
    read(a);

    return 0;
}