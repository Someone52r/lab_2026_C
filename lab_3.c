#include <stdio.h>
#include <stdlib.h>

#include "natur.h"

#define INT_MAX 2147483647

int N, M;
int sum = 0;
char *N_str = NULL;
char *M_str = NULL;
int buff;
int main() {

//===============================================================================

    while (1) {
        printf("Введите N: ");
        if (scanf("%ms", &N_str) != 1) {
            printf("Ошибка чтения.\n");
            free(N_str);
	    continue;
        }
        if (is_natural_string(N_str)) {
    	    N = atoi(N_str);
	    free(N_str);
	    break;
        } else {
	    free(N_str);
	    printf("Число должно быть натуральным!\n");
        }
    }

    while (1) {
        printf("Введите M: ");
        if (scanf("%ms", &M_str) != 1) {
            printf("Ошибка чтения.\n");
            free(M_str);
            continue;
        }
        if (is_natural_string(M_str)) {
            M = atoi(M_str);
	    free(M_str);
            break;
        } else {
	    printf("Чиcло должно быть натуральным!\n");
	    free(M_str);
	}
    }

//===============================================================================

	/*
	//mem create
	printf("print matrix sizes: N for rows, M for columns\n");
	scanf ("%i %i", &N, &M);
	*/
	int *matrix = (int *)malloc(N*M * sizeof(int));
	//matrix fill
	printf ("please imput %d digits for matrix\n", N*M);
	for (int i = 0; i<N; i++){
		for (int j = 0; j<M; j++){
			scanf ("%d", &matrix [i*M+j]);
		}
	}


	//КУСОК ОТ ИИ ЧИСТО ДЛЯ ПРОВЕРКИ РАБОТЫ
	    // --- ВИЗУАЛИЗАЦИЯ МАТРИЦЫ НА ЭКРАНЕ ---
	printf("\nYour Matrix (%dx%d):\n", N, M);
	for (int i = 0; i < N; i++) {
		printf("[ "); // Красивая открывающая скобка для строки
			for (int j = 0; j < M; j++) {
            // Выводим элемент. %4d резервирует 4 символа под число для ровных столбцов
			printf("%4d ", matrix[i * M + j]);
		}
		printf("]\n"); // Закрывающая скобка строки и переход на новую строчку
	}
	printf("\n");
	//Кусок от ии закончен

	//поиск минимального элемента и строки с этим номером
	int min = INT_MAX;
	int min_row;
	for (int i = 0; i<N; i++){
		for (int j = 0; j<M; j++){
			if (matrix[i*M+j]<min){
				min = matrix [i*M+j];
				min_row = i;
			}
		}
	}
	printf("min number %d, at %d row\n", min, min_row+1);
	//смена минимальной строки и 4-ой
	for (int j = 0; j<M; j++){
		buff = matrix[M*min_row+j];
		matrix[M*min_row+j] = matrix[M*3+j];
		matrix[M*3+j] = buff;
	}
	printf ("new matrix:\n");




	        //КУСОК ОТ ИИ ЧИСТО ДЛЯ ПРОВЕРКИ РАБОТЫ
            // --- ВИЗУАЛИЗАЦИЯ МАТРИЦЫ НА ЭКРАНЕ ---
        printf("\nYour Matrix (%dx%d):\n", N, M);
        for (int i = 0; i < N; i++) {
                printf("[ "); // Красивая открывающая скобка для строки
                        for (int j = 0; j < M; j++) {
            // Выводим элемент. %4d резервирует 4 символа под число для ровных столбцов
                        printf("%4d ", matrix[i * M + j]);
                }
                printf("]\n"); // Закрывающая скобка строки и переход на новую строчку
        }
        printf("\n");
        //Кусок от ии закончен





	//summ for rows 2 && 4
	for (int i = 1; i<4; i+=2) {
		for (int j = 0; j<M; j++) {
			sum += matrix[i*M+j];
		}
	}
	printf ("sum of elements of 2nd and 4th rows are: %i\n", sum);

	// mem free
//	for (int i = 0; i < N; i++)
//		free(matrix[i]);
	free(matrix);
	return 0;
}


/*
БЛОК КОММЕНТАРИЕВ
У нас есть: необходимость сделать матрицу, и уже готовое освобождение памяти под неё.
ПОЛЬЗОВАТЕЛЬ должен записать в матрицу каждое значение!!!
Сделай предупреждалку, чтобы пользователь не офигел от кол-ва вводимых данных (ну типа для матрицы более чем 6*6 сделать предупреждение.)



Комментарии по коду
Внутри mem create создаётся одномерный массив, размерности N*M, т.к. у нас N СТРОК и M СТОЛБЦОВ, N идёт первее

*/











/*
Лаба 3, вариант 9
1. Создать matrix N*M, вводимую с клавы (malloc) (СДЕЛАНО с проверкой на натуральность)
2.1. Найти строку содерж. мин. элем. матрицы (1 элемент) (СДЕЛАНО)
2.2. Найденную строку сменить местом с 4-ой (Сделано, НО не проверено пока что)
2.3. В получ. матрице подсчитать сумму всех элем. 2-ой и 4-ой строк (СДЕЛАНО)
*/
