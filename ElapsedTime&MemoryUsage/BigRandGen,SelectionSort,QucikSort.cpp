#include<iostream>
#include<Windows.h>
#include<ctime>

using namespace std;

#define SIZE 100000
#define ITMES_PER_LINE 10
#define FIRTSTLAST_PRINTSIZE 20

void genBigRandArray(int* array, int bigRandMax);
void copyArray(int* dset, int* src, int size);
void printBigArray(int* array, int size, int firstLastPrintSize);
int partition(int* array, int size, int left, int right, int pivotIndex,int level);
void quickSort(int* array, int size, int left, int right, int level);
void selectionSort(int* array, int size);

int main(){
	int* arr1, * arr2;
	LARGE_INTEGER freq, t1, t2;
	LONGLONG t_diff;
	double elapsed_time;

	arr1 = (int*)malloc(sizeof(int) * SIZE);
	arr2 = (int*)malloc(sizeof(int) * SIZE);

	srand(time(0));
	genBigRandArray(arr1, SIZE);
	genBigRandArray(arr2, SIZE);
	copyArray(arr2, arr1, SIZE);

	printf("\nGenerated int array (before sorting):\n");
	printBigArray(arr1, SIZE, FIRTSTLAST_PRINTSIZE);
	QueryPerformanceFrequency(&freq);

	printf("\nSorting arrray of %d integers with QucikSorting (org) ... \n", SIZE);
	QueryPerformanceCounter(&t1);
	quickSort(arr1, SIZE, 0, SIZE - 1, 0);
	QueryPerformanceCounter(&t2);
	t_diff = t2.QuadPart - t1.QuadPart;
	elapsed_time = ((double)t_diff / freq.QuadPart) * 1000000;
	printf("QuickSort tool %7.2f [millie-second] to sort %d integer array.\n", elapsed_time / 1000.0, SIZE);
	printf("\nSorted Array : \n");
	printBigArray(arr1, SIZE, FIRTSTLAST_PRINTSIZE);

	printf("Sorting array of %d integers with Selection Sorting ... \n", SIZE);
	QueryPerformanceCounter(&t1);
	selectionSort(arr2, SIZE);
	QueryPerformanceCounter(&t2);
	t_diff = t2.QuadPart - t1.QuadPart;
	elapsed_time = ((double)t_diff / freq.QuadPart) * 1000000;
	printf("SelctionSort tool %7.2f [millie-second] to sort %d integer array.\n", elapsed_time / 1000.0, SIZE);
	printf("\nSorted Array : \n");
	printBigArray(arr2, SIZE, FIRTSTLAST_PRINTSIZE);
	printf("\n");
}

void genBigRandArray(int* array, int bigRandMax){
}
void copyArray(int* dset, int* src, int size){
}
void printBigArray(int* array, int size, int firstLastPrintSize) {

}
int partition(int* array, int size, int left, int right, int pivotIndex, int level) {

}
void quickSort(int* array, int size, int left, int right, int level) {

}
void selectionSort(int* array, int size) {

}



