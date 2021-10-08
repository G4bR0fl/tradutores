int list lista;

int to_float(int num) {
    return num*3.1415;
}

int beq_100(float num, int a, int b, int c) {
    return num >= 100.00;
}

int list_operations() {
    int list int_list;
    int_list = NIL;
    int i;
    int k;
    k = beq_100(10, 20, 30, 40);
    int n;
    n = 100;
    for (i = 0; i < n ; i = i + 1) {
        lista = i : int_list;
    }

    float list float_list;
    float_list = to_float >> int_list;
    
    float list aux;

    for (aux=float_list; aux != NIL; aux = !aux) {
        int x;
        writeln(x * -?aux);
    }

    float list beq_list;
    beq_list = beq_100 << float_list;

    return -(?beq_list);
}

int main() {
    int a;
    a = 1;
    {
        int b;
        {
            int a;
            a = 2;
        }
        {
            int c;
            b = 3;
        }
        b = 4;
        a = 5;  
    }

    if(a == 3) {
        writeln("a eh 3");
    } else write("a eh 1");

    int c;
    read(c);
    if(c >= 10 || (c * 3 - (5/2 + 4) + c*(2+a)/3 && 1)) {
        return -(-a) + a*c || (a && c || a>1 && !c); 
    } else if(a > 1 && c != -a) {
        return a*c+(10*a - !(c) || 0);
    } else {
        return -100;
    }

    return 0;
}
