//Functions to help test sorts
#ifndef _TEST_LIB_H_
#define _TEST_LIB_H_

//Prototype Testing Functions

//Generate a Random Array
int* randomArray(int size);
//Print an Array
void printArray(int* A, int size);
//Copy an Array
int* copyArray(int* A, int size);
//Check If Sorted
int isSorted(int* A, int size);
//Check If All Values Appear
int hasSameValues(int* A, int* X, int sizeA, int sizeX);
//Count the number of copies of a number in an array
int count(int*A, int size, int target);
//Test a sort of size n
//Function to test is provided
int runTest(int n, void (*func)(int* A, int size));
//Run k tests at one size
int runMultTests(int n, int k, void (*func)(int* A, int size));
//Test all sides from 0 to n in powers of 2
int fullTestBed(int maxExp, void (*func)(int* A, int size) );
//Fast Power
int fastPow(int base, int exp);

#endif
