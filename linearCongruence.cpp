// linearCongruence.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include<stdio.h> 
#define a 1103515245
#define c 1
#define m 2147483648
#define SEARCH 386

// multiply the last number with a factor 'a' add constant 'c' then modulate by 'm'


unsigned int l_c_g(unsigned int x){
return (a*x + c)%m;
}

void bubbleSort(unsigned int* myarray, int size){

	int temp;
	for (int i = size; i > 0; i--)
		for (int j = 1; j <= i; j++)
			if (myarray[j-1] > myarray[j])
			{
				temp = myarray[j-1];
				myarray[j-1] = myarray[j];
				myarray[j] = temp;
			}
}

//returns -1 if searchTerm not found, otherwise the number of comparissons needed to find the term
int sequentialSearch(unsigned int* myarray, int size, int searchTerm){
	int comparrisons = -1;
	for(int i = 0; i < size; i++)
		if(myarray[i] == searchTerm)
			return comparrisons = i+1;
	return comparrisons;
}


int binarySearch(unsigned int* myarray, int* high, int* low, int searchTerm, int* counter){
	int middle = (*high + *low )/ 2;

	if (low >= high)
		return -1;
		if(myarray[middle] > searchTerm){
			*counter+=2;
			*high = middle;
			return binarySearch(myarray, high, low, searchTerm, counter);
		} else 
			if (myarray[middle] < searchTerm) {
				*counter +=3;
				*low = middle;
				return binarySearch(myarray, high, low, searchTerm, counter);
			}
			else
				if(myarray[middle] == searchTerm){
					counter += 4;
					return middle;
				}
	}



int main(){
unsigned int seed = 567;
unsigned int x;
//initialise with seed
x = l_c_g(seed);

//ready to extract values from l_c_g
//e.g.:

int size = 100;

//no dynamic allocation

unsigned int myarray[100];

for (int i = 0; i < size; i++){
	x = l_c_g(x);
	myarray[i] = x%400;
}

FILE *file;

if (file = fopen("randomNumbers.txt", "w"))
{
	for(int i = 0; i < size; i++)
		fprintf(file, "%d\n", myarray[i]);
} else{
	printf("Output file failed to open");
}

//bubble sort time

bubbleSort(myarray, size);

if (file = fopen("sortedRandomNumbers.txt", "w"))
{
	for(int i = 0; i < size; i++)
		fprintf(file, "%d\n", myarray[i]);
} else{
	printf("Output file failed to open");
}

//search for a number sequential search:
int comparrisons;
((comparrisons = sequentialSearch(myarray, size, SEARCH)) == -1? printf("sequential -> Search term not found\n"): printf("sequential -> Number of comparrisons to find search term: %d\n",comparrisons));

int high= 100, low = 0, counter = 0;

	((comparrisons = binarySearch(myarray, &high, &low, SEARCH, &counter) == -1? printf("Binary -> Search term not found\n"): printf("Binary -> Number of comparrisons to find search term: %d\n",counter)));


/*	through our great a glorious knowledge of the seed :-)
	these numbers will be used to run question 5 esentially counting the number of comparrisons for sequential search and binary search 10 times.
	the numbers will be the first 10 numbers from the random unsorted list and the searches will be performed on the sorted list.

	125
	122
	83
	200
	249
	374
	351
	212
	261
	386

*/
	int testvalues[] = {122,83,200,249,374,351,212,261,386,125};
	int binaryComparisons[10];
	int sequentialComparisons[10];

	if (file = fopen("Comparisons.txt", "w"))
{
	for(int i = 0; i < 10; i++)
	{
		counter = 0;
		high = 100;
		low = 0;
		sequentialComparisons[i] = sequentialSearch(myarray, size, testvalues[i]);
		binaryComparisons[i] = binarySearch(myarray, &high, &low, testvalues[i], &counter);
		fprintf(file,"seq: %d     bin: %d\n", sequentialComparisons[i], counter);
	}
} else{
	printf("Output file failed to open");
}

	return 0;
}





