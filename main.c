#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

void mostra_float (void *info){ //Mostra um dado float a partir de um ponteiro void
	float *p = info;
	printf("%.2f\n", *p);
}

void mostra_int (void *info){ //Mostra um dado int a partir de um ponteiro void
	int *p = info;
	printf("%d\n", *p);
}

void mostra_char (void *char){ //Mostra um dado char a partir de um ponteiro void
	char *p = info;
	printf("%c\n", *p);
}

int main (){
	printf("ola mundo");
	return 0;
}