#include "usefulFunc_9.h"
int editTheNote(char *name) {

	FILE *f; int i;
	fopenCorrectly(&f, name, "r+b");

	puts("Input the paramets of product you want to edit in the database");
	if (!(i = findThePlaceOfNote(f))) { puts("There are no such notes."); system("pause"); return -1; }//return  -1 if we could not find the note

	product prod;
	freadProduct(&prod, f);

	puts("\n\nThe parameters of the old product:\n");
	printProduct(&prod);

	puts("\nInput parameters of new product, if you do not want to change text parameter - input empty string,"
		"\nif you do not want to change price, input negative number:\n");

	char name1[15], description[15], export_ctr[15]; double price;

	readParam("Name", name1, 14);
	readParam("Description", description, 14);
	readParam("Country, which is exported", export_ctr, 14);
	printf("Price:"); readDoubleClearly(&price);

	if (strlen(name1) > 1)  strcpy(prod.name, name1); 
	if (strlen(description) > 1)  strcpy(prod.description, description); 
	if (strlen(export_ctr) > 1)  strcpy(prod.export_ctr, export_ctr); 

	if (price >= 0) prod.price = price;

	fseek(f, -(int)sizeof(product), SEEK_CUR);
	fwrite(&prod, sizeof(product), 1, f);

	fclose(f);
	return 0;
}
