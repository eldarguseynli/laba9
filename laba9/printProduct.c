#include "product.h"

int printProduct(product *prod) {
	printf("Name: %s\n", prod->name);
	printf("Description: %s\n", prod->description);
	printf("Country, which is exported: %s\n", prod->export_ctr);
	printf("Price: %.2lf", prod->price);
}