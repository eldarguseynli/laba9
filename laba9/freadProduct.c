#include "product.h"

int freadProduct(product *p, FILE *f) {
	fread(p, sizeof(product), 1, f);
	return 0;
}