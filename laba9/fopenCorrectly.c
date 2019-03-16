#include "tools_9.h"

void fopenCorrectly(FILE **f, char *name, char *mode) {
	if ((*f = fopen(name, mode)) == NULL) { printf("Cannot open file.\n"); system("pause"); exit(1); }
}