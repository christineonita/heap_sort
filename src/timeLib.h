#ifndef _TIME_LIB_H_
#define _TIME_LIB_H_

//Run all timings and print a table
//Tests sizes 0 to 2^b
void runTimings(int b);

//Time One Function
double timeFunc(int size, void (*func)(int* A, int n));

#endif
