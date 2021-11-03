.table
int a_1
int b_1
int c_1
int a_2
int b_2
int c_2
float elem_4
char _str0[] = "Digite um novo elemento da lista:"
int a_5
float b_5
int c_5
float d_5
char _str1[] = "Lista com head e tail"

.code
mul $0, a_1, b_1
mul $1, $0, 15
mov c_1, $1
mov a_2, 10
mov b_2, 20
mov c_2, 30
sleq $0, a_2, b_2
not $0, $0
sleq $0, c_2, a_2
not $0, $0
slt $2, a_2, $0
println _str0
scanf elem_4
mov c_5, $0
println _str1
scani a_5
