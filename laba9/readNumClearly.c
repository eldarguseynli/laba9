#include "tools_9.h"

void readDoubleClearly(double *x) {
	if (!(scanf("%lf", x))) raise_val_error("You had to input number. Termination of the programm."); clear();
}

void readIntClearly(int *n) {
	if (!(scanf("%d", n))) raise_val_error("You had to input number. Termination of the programm."); clear();
}