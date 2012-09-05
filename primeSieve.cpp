// primeSieve.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <math.h>
#include <stdlib.h>
//definately need a better isqrt algorithm :-)
unsigned long long isqrt(unsigned long long x){
	return (unsigned long long)sqrt(double(x));
}


int _tmain(int argc, _TCHAR* argv[])
{
	//input
	unsigned long long maxPrime = 500000000;
	unsigned long long maxSearch = isqrt(maxPrime);

	//creating a bit string the length of maxSearch

	bool * bitString;

	bitString = (bool *)malloc((sizeof(bool)*maxPrime) + 1);

	//initialise bit string to true's

	for(unsigned long long i = 0; i < maxPrime; i++)
		bitString[i] = false;

	//sieve

	//let [1] = 1
	unsigned long long counter;
	unsigned long long j;
	for(counter = 2; counter < maxSearch; counter++) 
		//small optimisation starting from square of number
		for(j = counter * counter; j < maxPrime; j += counter) 
		(bitString[j] ? 0 : bitString[j] = true );

	//once bitString is completed print it to file:

	FILE *file;

if (file = fopen("dataOutput.txt", "w"))
{
	for(unsigned long long i = 2; i < maxPrime; i++)
		if(!bitString[i])
		fprintf(file, "%d\n", i);
} else{
	printf("Output file failed to open");
}

	return 0;
}

