// linearCongruence.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include<stdio.h> 

// multiply the last number with a factor 'a' add constant 'c' then modulate by 'm'
unsigned int l_c_g(unsigned int x){
unsigned int a = 1103515245;
unsigned int c = 1;
unsigned int m = 2147483648;
return (a*x + c)%m;
}

void bubbleSort(int* a, int size){

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

for (unsigned int i = 0; i < size; i++)
	myarray[i] = x = l_c_g(x);

FILE *file;

if (file = fopen("dataOutput.txt", "w"))
{
	for(unsigned int i = 0; i < size; i++)
		fprintf(file, "%d\n", myarray[i]);
} else{
	printf("Output file failed to open");
}
	return 0;
}





