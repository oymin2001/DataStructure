#include<iostream>

int binary_search(int list[], int n, int key) {
	int low, high, middle;
	low = 0;
	high = n - 1;
	while (low <= high) {
		middle = (low + high) / 2;
		if (key == list[middle])
			return middle;
		else if (key > list[middle])
			low = middle + 1;
		else
			high = middle - 1;
	}
	return -1;
}
int selection_sort(int list[],int size) {
	int min,tmp; //  string_seleciton_sort -> char tmp[MAX_WORD_LENGTH];

	for (int i = 0; i < size-1; i++)
	{
		min = i;
		for (int j = 0; j < size; j++)
		{
			if (list[j] < list[min]) // string_seleciton_sort -> strcmp(list[min],list[j])>0
				min = j;
			if (min != i)
			{
				tmp = list[i]; // string_seleciton_sort -> strcpy(tmp,list[i]);
				list[i] = list[min]; // string_seleciton_sort -> strcpy(list[i],list[min]);
				list[min] = tmp; // string_seleciton_sort -> strcpy(list[min],tmp);
			}
		}
	}
	return -1;
}

//QucikSort

int partition(int array[],int left,int right,int pivotIndex){
	int pivotValue = array[pivotIndex];
	int tmp;
	tmp = array[pivotIndex];
	array[pivotIndex] = array[right];
	array[right] = tmp;
	int L = left;
	int R = right - 1;
	while (L <= R) {
		while ((L <= R) && (array[L] <= pivotValue))
			L++;
		while ((R >= L) && (array[R] >= pivotValue))
			R--;
		if (L < R) {
			tmp = array[L];
			array[L] = array[right];
			array[right] = tmp;
		}
	}
	return L;
}

void QucikSort(int array[], int left, int right) {

	if (left >= right)
		return;
	else if (left < right)
	{
		int pi = (left + right) / 2;
		int new_pi = partition(array, left, right, pi);

		if (left < (new_pi - 1))
			QucikSort(array, left, new_pi - 1);
		if (right > (new_pi + 1))
			QucikSort(array, new_pi + 1, right);
	}
}
