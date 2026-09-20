#include <stdio.h>
#include <math.h>
float min_U=3.402823466e+38F, min_x, min_y, min_z;
int main (float U) {
    for (float x=1; x<=3; x=x+1.3) {
        for (float y=2; y<=4; y=y+1.3) {
            for (float z=0.5; z<=1.5; z=z+0.8) {
                U=-sqrt(pow(y, 2)+4*pow(x, 2)/3)+5*pow(cosf(x*y), 4)/(x*z);
                printf ("%f\n", U);
                if (U>2.1 && U<min_U) {
                    min_U = U;
                    min_x = x;
                    min_y = y;
                    min_z = z;                    
                }
            }
        }
    }
    printf ("min U>2.1 is: %f, and xyz is: %f, %f, %f\n", min_U, min_x, min_y, min_z);
    return 0;
}

/* Лабораторная работа №1, задание номер 9.
Пояснения: в 3-ей строке, для min_U было дано значение float limit,  
чтобы затем проверка двойного условия (строка 10) работало корректно.
т.к. иначе при не заданном значении для min_U оно бы просто выдало нулевой результат.
Формула для U написана как можно более компактно, нет смысла её размазывать.*/