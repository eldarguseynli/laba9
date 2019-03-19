#include "tools_9.h"

void readParam(char *atr_name, char *param, int n) {
	printf("%s: ", atr_name);
	getClearly(param, n); //check overload and clear buffer
	param[strlen(param) - 1] = 0;
}

void read_validateParam(char *atr_name, char *param, int n) {
	readParam(atr_name, param, n);
	if (!strlen(param)) { raise_val_error("You`ve inputed empty string"); }
}

void readDoubleParam(char *atr_name, int *double_param) {
	printf("%s: ", atr_name); readDoubleClearly(double_param); if (*double_param < 0) raise_val_error("Value of price must be not negative");
}