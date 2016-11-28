#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

	int aInt = 1;
	char str[15];
	sprintf(str, "%d", aInt);

	printf("\n\tSe paso de int: %i a str: %s\n",aInt,str);


}
