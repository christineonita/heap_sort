#include <stdio.h> //For printf
#include <stdlib.h> //For rand and srand
#include <time.h> //For time

//Local Imports
#include "heap.h"
#include "testLib.h"

//Always tests heapsort
//Main Program
int main(int argc, char** argv){
	//Set the random number generator
	srand(time(0));
	//What is the max size to test with
	int maxSize = 13;
	//Get only the first letter
	printf("Testing Heap Sort\n");
	fullTestBed(maxSize, heapSort);
	return 0;
}
