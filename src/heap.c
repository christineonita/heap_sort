#include <stdio.h>
#include <stdlib.h>
#include "heap.h"


int pickSmallerChild(struct Heap* H, int leftIndex, int rightIndex);
void expand(struct Heap* H);
/*
struct Heap{
	int* data;
	int maxSize;
	int currentSize;
};
*/

void heapSort(int* Array, int size){
	struct Heap* H = makenull(size);
	for (int i = 0; i < size; i++){
		insert(Array[i], H);
	}
	int i = 0;
	while(!empty(H)){
		Array[i] = min(H);
		deletemin(H);
		i++;
	}
	free(H);
}

//Make a new Heap
struct Heap* makenull(int capacity){
	struct Heap* H = (struct Heap*)malloc(sizeof(struct Heap));
	H->data = malloc(capacity * sizeof(int));
	H->currentSize = 0;
	H->maxSize = capacity;
	return H;
}

//Is the heap empty?
char empty(struct Heap* H){
	if (H->currentSize == 0){
		return 1;
	}
	else {
		return 0;
	}
}

//What is the min?
int min(struct Heap* H){
	if (empty(H)){
		return 0;
	}
	else {
		return H->data[0];
	}
}

//Delete the min
void deletemin(struct Heap* H){
	if (empty(H)){
		return;
	}
	swap(H, 0, H->currentSize - 1);
	H->currentSize = H->currentSize - 1;
	downheap(H, 0);
}

//Downheap a value at index i
void downheap(struct Heap* H, int i){
	int leftIndex = leftChild(i);
	int rightIndex = rightChild(i);
	if (leftIndex >= H->currentSize){
		return;
	}
	int minIndex = pickSmallerChild(H, leftIndex, rightIndex);
	if (H->data[i] > H->data[minIndex]){
		swap(H, i, minIndex);
		downheap(H, minIndex);
	}
	return;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
int pickSmallerChild(struct Heap* H, int leftIndex, int rightIndex){
	int minIndex;
	if (rightIndex >= H->currentSize){
		minIndex = leftIndex;
	}
	else {
		if (H->data[leftIndex] < H->data[rightIndex]){
			minIndex = leftIndex;
		}
		else {
			minIndex = rightIndex;
		}
	}
	return minIndex;
}

void expand(struct Heap* H){
	int newSize = 2 * H->currentSize;
	int newData[newSize];
	for (int i = 0; i < H->currentSize; i++){
		newData[i] = H->data[i];
	}
	H->data = newData;
	H->maxSize = newSize;
	return;
}
////////////////////////////////////////////////////////////////////////////////////////////////

//Insert a new value
void insert(int x, struct Heap* H){
	if (H->currentSize == H->maxSize){
		expand(H);
	}
	H->data[H->currentSize] = x;
	H->currentSize++;
	upheap(H, H->currentSize - 1);
	return;
}

//Upheap a value at index i
void upheap(struct Heap* H,int i){
	int p = parent(i);
	if (p < 0){
		return;
	}
	if (H->data[p] <= H->data[i]){
		return;
	}
	swap(H, i, p);
	upheap(H, p);
}

//Get Index of Parent
int parent(int n){
	if (n == 0){
		return -1;
	}
	else {
		return ((n - 1)/2);
	}
}

//Get index of Left Child
int leftChild(int n){
	return ((2*n) + 1);
}

//Get index of Right Child
int rightChild(int n){
	return ((2*n) + 2);
}

//Swap i and j in heap
void swap(struct Heap* H, int i, int j){
	int temp = H->data[i];
	H->data[i] = H->data[j];
	H->data[j] = temp;
	return;
}

//Just to help debug
//You will want to use this if anything goes wrong in your code
void printHeap(struct Heap* H){
	printf("Heap Current Size: %d\n", H->currentSize);
	printf("Heap Max Size: %d\n", H->maxSize);
	printf("Contents:\n");
	for (int i = 0; i < H->currentSize; i++){
		printf("%d ", H->data[i]);
	}
	printf("\n");
}

