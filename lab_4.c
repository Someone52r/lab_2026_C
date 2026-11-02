#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void bubble(int *arr, int n);
void merge (int *arr, int n);
void inser (int *arr, int n);

void random_filler (int *arr, int n){
	for (int i = 0; i<n; i++){
		arr[i] = rand ();
	}
}
void copy_arr (int *imp, int *out, int n){
	for (int i = 0; i<n; i++){
		imp[i]=out[i];
	}
}
int main () {
	int sizes[] = {10, 1000, 10000, 100000};
	int num_size = 8;
	printf ("_____________________________________________________________\n");
	printf ("| ArrSize    |  bubble(sec) | merge(sec)   | insertion (sec)|\n"); //10|12|12|12
	printf ("_____________________________________________________________\n");
	srand(time(NULL));
	for (int a = 0; a<num_size; a++){
		int n = sizes[a];
		//mem crea
		int *arr = (int *)malloc(n * sizeof(int));
		int *arr_b = (int *)malloc(n * sizeof(int));
		int *arr_m = (int *)malloc(n * sizeof(int));
		int *arr_i = (int *)malloc(n * sizeof(int));
		if (arr == NULL || arr_b == NULL || arr_m == NULL || arr_i == NULL){
			printf ("Array_error\n");
			return 1;
		}
		random_filler (arr, n);
		copy_arr (arr, arr_b, n);
		copy_arr (arr, arr_m, n);
		copy_arr (arr, arr_i, n);
		double t_b = 0.0, t_m = 0.0, t_i = 0.0;
		clock_t start = clock();
		bubble (arr_b, n);
		clock_t end = clock();
		t_b = (double)(end - start) / CLOCKS_PER_SEC;
		start = clock();
		merge(arr_m, n);
		end = clock();
		t_m = (double)(end - start) / CLOCKS_PER_SEC;
		start = clock();
		inser (arr_i, n);
		end = clock();
		t_i = (double)(end - start) / CLOCKS_PER_SEC;
		printf ("| %-10d | %-12f | %-12f | %-12f |\n", n, t_b, t_m, t_i);
		//mem free
		free (arr);
		free (arr_b);
		free (arr_m);
		free (arr_i);
	}
	printf ("_____________________________________________________________\n");\
	return 0;
}





//сортировка слиянием
void merge (int *arr, int n, unsigned int l, unsigned int r) {
	int* down = (int *)malloc(n*sizeof(int));
	if (l == r){
		down[l] = up[l];
		return down;
	}
	unsigned int middle = l+(r-l)/2;
	int *l_buff = merge_sort(up, down, l, middle);
	int *r_buff = merge_sort(up, down, middle+1, r);
	// слияние двух отсортированных половин
	int *target = l_buff == up ? down : up;
	unsigned int l_cur = l, r_cur = middle + 1;
	for (unsigned int i = l; i <= r; i++){
		if (l_cur <= middle && r_cur <= r){
			if (l_buff[l_cur] < r_buff[r_cur]){
				target[i] = l_buff[l_cur];
				l_cur++;
			}else{
				target[i] = r_buff[r_cur];
				r_cur++;
			}
		} else if (l_cur <= middle){
			target[i] = l_buff[l_cur];
			l_cur++;
		}else{
			target[i] = r_buff[r_cur];
			r_cur++;
		}
	}
	free (l_buff);
	free (r_buff);
	free (down);
	return target;
}


//сортировка вставками
void inser (int *arr, int n){
	for (int i = 1; i < n; i++) {
		int key = arr[i];
		int j = i - 1;
		while (j>=0 && arr[j] > key) {
			arr[j+1] = arr[j];
			--j;
		}
		arr[j + 1] = key;
	}
}




//сортировка пузырьком
void bubble (int *arr, int n){
	for (int i = 1; i <= n - 1; i++) {
		int f = 0;
		for (int j = 0; j <= n - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				f = 1;
			}
		}
		if (f==0) {
			break;
		}
	}
}





/*
Лаба
Сделай 3 сортировки: пузырьком, вставками и слиянием
Массивы для теста размерами от: 10, 1000, 10000 и 100000
Надо замерить и сравнить время работы каждой из сортировок. Массивы генить через "rand()", задавать динамически.
В результате вывод должен быть в виде таблицы, содержащий результаты для сравнения.
*/
