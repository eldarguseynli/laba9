#include "usefulFunc_9.h"

int createFile(char *name, int *n)
{
	FILE *f;
	fopenCorrectly(&f, name, "w+b");
	for (int i = 0; i < n; i++) { 
		printf("\nThe %d product:\n\n", i+1);
		fillFile(f); 
	}

	fclose(f);
	return 0;
}