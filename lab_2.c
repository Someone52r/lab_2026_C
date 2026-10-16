#include <stdio.h>

int N, M;
int digit (int n){
    int exp = 1;
    while (n >= 10){
        n/=10;
        exp ++;
    }
    return exp;
}
int numb (int n, int b, int c){
    int a = 1;
    for (int i = 0; i < c - 1 - b; i++)
        a *=10;
    return (n/a) % 10;
}
int brute_force (int n, int f, int l, int a) {
    if (f >= l) 
        return 1;
    if (numb(n, f, a) != numb (n, l, a))
        return 0;
    return brute_force (n, ++f, --l, a);
}
void palindro (int a, int b){
    if (a>b)
        return;
    if (a>=0 && brute_force (a, 0, digit(a)-1, digit(a)))
        printf ("%d ", a);
    palindro (++a, b);
}
int main () {
    printf ("input two numbers for palindromes search area:\n");
    scanf ("%i %i", &N, &M);
    printf ("area between %i && %i will be checked\n", N, M);
    if (N > M) {
        int t = N; N = M; M = t; 
    }
    palindro (N, M);
    printf ("\n");
    return 0;
}
/*
Комментарии
В строке № 14 "c-1-b" — индекс цифры, с учётом того, что первая - считается нулём
В строке № 16, n/=10 эквивалентно записи n = n / 10, отбрасывая остаток от деления, получая экпонентную часть числа
Строка 22, объявление переменной n. В функции numb, n  используется как степень 10. т.е. 10^0, когда n = 1, а затем с каждым проходом растёт
Строки 36 и 37 для смены N и M значениями, чтобы в дальнейшем не приходилось делать в каждой функции проверку
*/





/*
Составить рекурсивный алгоритм по следующей задаче:
Даны два натуральных числа N и M, которые образуют диапазон чисел. Оба числа вводятся пользователем с клавиатуры. В этом диапазоне необходимо найти цепочку чисел, которые являются полидромами и вывести ее. Также требуется проверить, что вводимые данные корректны
Пример
N = 1000 M = 2000
Ответ — 1001 1111 1221 и так далее
*/