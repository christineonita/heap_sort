#include "timeLib.h"
#include "testLib.h"
#include "heap.h"
#include <time.h> //For clock
#include <stdio.h> //For printf
#include <stdlib.h> //For free

//Runs all timings and makes a table
//Inputs: Max Size by exponent of 2
//	for int b times size 1 to 2^b
//Outputs: Done
//Side Effects: Prints Table to Screen
void runTimings(int b){
	char* t1="Size";
	char* t2="Heap";
	printf("Time in Seconds shown.\n");
	printf("Time to create arrays is not counted. Only sorting.\n");
	printf("| %6s | %9s |\n",t1,t2);
	for(int p=0; p <= b; p++){
		int size = fastPow(2,p);
		double h = timeFunc(size,heapSort);
		printf("| %6d | %9.4f |\n"
			   ,size,h);
	}
}

//Time a single sort
//for a single size
//Inputs: Size and Function to time
//Outputs: Time taken (milliseconds)
//Side Effects: None
double timeFunc(int size, void (*func)(int* A, int n)){
	//To store times
	clock_t start, stop;
	//Make Array
	int* A = randomArray(size);
	start = clock();
	func(A,size);
	stop = clock();
	double timePassed = (double)(stop - start) / CLOCKS_PER_SEC;
		free(A);
	return timePassed;
}
