#include "usefulFunc_9.h"

int addTheNote(char *name) {
	int n;
	printf("Input how much goods you want to add to the database: ");
	readIntClearly(&n);

	FILE *f;
	fopenCorrectly(&f, name, "a+b");
	for (int i = 0; i < n; i++) {
		printf("\nThe %d product:\n\n", i + 1);
		fillFile(f);
	}

	fclose(f);
	return 0;
}