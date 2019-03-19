#include "usefulFunc_9.h"

int createFile(char *name)
{

	int n;
	printf("Input how much goods you want to input to the database: ");
	readIntClearly(&n);

	FILE *f;
	fopenCorrectly(&f, name, "wb");
	for (int i = 0; i < n; i++) {
		printf("\nThe %d product:\n\n", i + 1);
		fillFile(f);
	}

	fclose(f);
	return 0;
}