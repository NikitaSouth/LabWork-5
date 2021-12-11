//Лабораторная работа №5
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int arrayFill(int*, int);
int arrayOutput(int*, int);
int firstSort(int*, int);
int secondSort(int*, int, int);
int lookForNegs(int*, int);
int shiftSize(int*, int);
int arrayShift(int*, int, int);

int main()
{
	int* arr;
	int elementNumber, neg, shift;
	printf("Enter amount of elements of the array: ");
	scanf_s("%d", &elementNumber);
	if(elementNumber <= 0){
		printf("Array must be bigger than 0\a");
	} else{
		arr = (int*)malloc(sizeof(int) * elementNumber);
		if (arr == NULL){
			printf("An error in memory allocation has occured\a");
			return 0;
		}
		arrayFill(arr, elementNumber);
		firstSort(arr, elementNumber); //пузырьковая сортировка по возрастанию
		printf("Sorted array:\n");
		neg = lookForNegs(arr, elementNumber);
		secondSort(arr, elementNumber, neg); //сортировка по убыванию отрицательных
		shift = shiftSize(arr, elementNumber);
		arrayShift(arr, elementNumber, shift); //смещение членов влево, пока на первом месте не положительное
		arrayOutput(arr, elementNumber);
		free(arr);
	}
	return 0;
}

int arrayFill(int* arrayName, int arraySize)
{
	for (int i = 0; i < arraySize; i++){
		printf("arr[%d] = ", i);
		scanf_s("%d", &*(arrayName + i));
	}
}

int arrayOutput(int* arrayName, int arraySize)
{
	for (int i = 0; i < arraySize; i++){
		printf("arr[%d] = %d\n",i, *(arrayName + i));
	}
}

int firstSort(int* arrayName, int arraySize)
{
	int temp;
	for (int i = 0; i < arraySize - 1; i++){
		for (int j = 0; j < arraySize - i - 1; j++){
			if (*(arrayName + j) > *(arrayName + j + 1)){
				temp = *(arrayName +j);
				*(arrayName + j) = *(arrayName + j + 1);
				*(arrayName + j + 1) = temp;
			}
		}
	}
}

int secondSort(int* arrayName, int arraySize, int negs)
{
	int temp;
	for (int i = 0; i < negs - 1; i++){
		for (int j = 0; j < negs - i - 1; j++){
			if (*(arrayName + j) < *(arrayName + j + 1)){
				temp = *(arrayName + j);
				*(arrayName + j) = *(arrayName + j + 1);
				*(arrayName + j + 1) = temp;
			}
		}
	}
}

int lookForNegs(int* arrayName, int arraySize)
{
	int negs = 0;
	while(*(arrayName + negs) < 0){
		negs++;
	}
	return negs;
}

int shiftSize(int* arrayName, int arraySize)
{
	int shSize = 0;
	while(*(arrayName + shSize) <= 0){
		shSize++;
	}
	return shSize;
}

int arrayShift(int* arrayName, int arraySize, int shift)
{
	for (int i = 0; i < shift; i++){
		int temp = *arrayName;
		for (int j = 1; j < arraySize; j++){
			*(arrayName + j - 1) = *(arrayName + j);
		}
		*(arrayName + (arraySize - 1)) = temp;
	}
}