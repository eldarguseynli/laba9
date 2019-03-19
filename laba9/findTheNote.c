#include "usefulFunc_9.h"
int findTheNote(char *name) {
	FILE *f;
	fopenCorrectly(&f, name, "rb");

	puts("Input the paramets of product you want to find in the database");
	if (!(findThePlaceOfNote(f))) { puts("There are no such notes."); system("pause"); return -1; } //return -1 if we have not found such product

	product prod;
	freadProduct(&prod, f);

	puts("\nThe parameters of the found product:");
	printf("Name: %s\n", prod.name );
	printf("Description: %s\n", prod.description);
	printf("Country, which is exported: %s\n", prod.export_ctr);
	printf("Price: %.2lf", prod.price);

}