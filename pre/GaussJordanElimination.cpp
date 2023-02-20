#include<iostream>
#define SIZE_4 4
#define EPSILON 0.000001
#define SIZE 5


void addMtrx(int A[][SIZE_4], int B[][SIZE_4], int X[][SIZE_4], int size);
void subtractMtrx(int A[][SIZE_4], int B[][SIZE_4], int X[][SIZE_4], int size);
void multiplyMtrx(int A[][SIZE_4], int B[][SIZE_4], int X[][SIZE_4], int size);

void diagonalize(double augMtrx[SIZE][SIZE + 1], int size, int* solExist);
void pivoting(double augMtrx[SIZE][SIZE + 1], int size,int p, int* piv_found);
void printAugMtrx(double augMtrix[SIZE][SIZE + 1], int size);

int main() {
	int size;
	double X[SIZE];
	double augMtrx[SIZE][SIZE + 1];
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE+1; j++)
		{
			augMtrx[i][j] = rand() % 30;
		}

	}
	int i, j, solExist = 1, error = 0;
	double d;

	size = SIZE;
	printf("Augmented Matrix (size:%d)\n", size);
	printAugMtrx(augMtrx, size);

	diagonalize(augMtrx, size, &solExist);
	if (solExist) {
		printf("The solution of the given linear system:\n");
		for (int i = 0; i < size; i++)
		{
			X[i] = augMtrx[i][size];
			printf("X[%d] : %7.2f\n", i, augMtrx[i][size]);
		}
	}
	else
		printf("No unique solution\n");
}


void printAugMtrx(double augMtrix[SIZE][SIZE + 1], int size) {

	unsigned char a6 = 0xA6, a1 = 0xA1, a2 = 0xA2;
	unsigned char a3 = 0xA3, a4 = 0xA4, a5 = 0xA5;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if ((i == 0) && (j == 0))
				printf("%c%c%8.2f", a6, a3, augMtrix[i][j]);
			else if ((i == 0) && j == (size - 1))
				printf("%8.2f%c%c", augMtrix[i][j], a6, a4);
			else if ((i > 0) && (i < size - 1) && (j == 0))
				printf("%c%c%8.2f", a6, a2, augMtrix[i][j]);
			else if ((i > 0) && (i < size - 1) && (j == (size - 1)))
				printf("%8.2f%c%c", augMtrix[i][j], a6, a2);
			else if ((i == (size - 1)) && (j == 0))
				printf("%c%c%8.2f", a6, a6, augMtrix[i][j]);
			else if ((i == (size - 1)) && (j == (size - 1)))
				printf("%8.2f%c%c", augMtrix[i][j], a6, a5);
			else
				printf("%8.2f", augMtrix[i][j]);
		}
		printf("\n");
	}

}

void addMtrx(int A[][SIZE_4], int B[][SIZE_4], int X[][SIZE_4], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
		{
			X[i][j] = A[i][j] + B[i][j];
		}
	}
}

void subtractMtrx(int A[][SIZE_4], int B[][SIZE_4], int X[][SIZE_4], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
		{
			X[i][j] = A[i][j] - B[i][j];
		}
	}
}

void multiplyMtrx(int A[][SIZE_4], int B[][SIZE_4], int X[][SIZE_4], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
		{
			X[i][j] = 0;
			for (int k = 0; k < size; k++)
			{
				X[i][j] = A[i][k] * B[k][j];
			}
		}
	}
}

void pivoting(double augMtrx[SIZE][SIZE + 1], int size, int p, int* piv_found) {

	double xmax = 0.0, xtmp;
	int j, k, max_row;

	xmax = fabs(augMtrx[p][p]);
	max_row = p;
	for (j = p + 1; j < size; j++) 
	{
		if (fabs(augMtrx[j][p]) > xmax) {
			xmax = fabs(augMtrx[j][p]);
			max_row = j;
		}
	}
	if (fabs(xmax) < EPSILON)
		*piv_found = 0;
	else {
		*piv_found = 1;
		if (max_row != p) {
			for (k = p; k <= size; k++)
			{
				xtmp = augMtrx[p][k];
				augMtrx[p][k] = augMtrx[max_row][k];
				augMtrx[max_row][k] = xtmp;
			}
		}
	}
}

void diagonalize(double augMtrx[SIZE][SIZE + 1], int size, int* solExist) {
	int j, k, p = 0;
	double pivot, w;

	for (p = 0; (*solExist) && (p < size); p++) {
		printf("Pivoting at p=%d\n");
		pivoting(augMtrx, size, p, solExist);
		printAugMtrx(augMtrx, size);
		if (*solExist) {
			if (augMtrx[p][p] != 1.0) {
				pivot = augMtrx[p][p];
				augMtrx[p][p] = 1.0;
				for (k = p + 1; k <= size; k++)
					augMtrx[p][k] /= pivot;
			}
		}
		else
			break;

		for (j = 0; j < size; j++) {
			if ((j != p) && (augMtrx[j][p] != 0.0)) {
				w = augMtrx[j][p];
				augMtrx[j][p] = 0.0;
				for (k = p + 1; k <= size; k++) {
					augMtrx[k][k] -= w * augMtrx[p][k];
				}
			}
		}
		printf("After diagonalizing at p %d\n", p);
		printAugMtrx(augMtrx, size);
	}
}