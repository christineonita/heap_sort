#include <stdlib.h>//atoi
#include <stdio.h>//printf
#include <time.h> //For time
#include "timeLib.h"

//This function times a number of sorts
//It takes 1 command line argument
//the maximum exponentb  of 2^b to test with

//Depending on your computer, you will
//have to increase or decrease b to get
//good results

//This program times all the sorts
//Print a Usage Error Message
void printUsage();

//Collect Some Timings
int main(int argc, char** argv){
	if(argc!=2){
		printUsage();
		return -1;
	}
	//Set the random number generator
	srand(time(0));
	//Run Timings
	int b = atoi(argv[1]);
	runTimings(b);
	return 0;
}
//Print a Usage Error Message
//Input: None
//Output: None
//Side Effect: Prints Command Line Arguments
void printUsage(){
	printf("One Command Line Argument is required.\n");
	printf("Times Sorts from 1 to 2^b in array size.\n");
	printf("Give the largest exponent b of 2^b for the experiments.\n");
}
