#include "usefulFunc_9.h"
#include <stdlib.h>

void fjoin_prod(FILE *f, product *p, int n);
int prodcmp_name(const product *prod1, const  product *prod2);
int prodcmp_country(const product *prod1, const  product *prod2);
int prodcmp_price(const product *prod1, const  product *prod2);
int prodcmp_description(const product *prod1, const product *prod2);

int sortTheNotes(char *name){

	puts("\nOf what parameter do you want to sort products:\n");
	puts("1. Name");
	puts("2. Country, which is exported");
	puts("3. Price");
	puts("4. Description\n");

	int choice;  printf("Your choice: "); readIntClearly(&choice);

	FILE *f;
	fopenCorrectly(&f, name, "r+b");
	int l = filelength(_fileno(f));

	product *prods = (product*)malloc(l);
	if (!prods) { fputs("Memory was not allocated. Terminating the programm", stderr); system("pause"); exit(1); }

	fjoin_prod(f, prods, l / sizeof(product)); rewind(f); //make array of products from file and then return carriage to the begining of file

	switch (choice)
	{
	case 1:
	{
		qsort(prods, l / sizeof(product), sizeof(product), prodcmp_name);
		fwrite(prods, sizeof(product), l / sizeof(product), f); //sort array and then write it in the file 
		break;
	}
	case 2:
	{
		qsort(prods, l / sizeof(product), sizeof(product), prodcmp_country);
		fwrite(prods, sizeof(product), l / sizeof(product), f);
		break;
	}
	case 3:
	{
		qsort(prods, l / sizeof(product), sizeof(product), prodcmp_price);
		fwrite(prods, sizeof(product), l / sizeof(product), f);
		break;
	}
	case 4:
	{
		qsort(prods, l / sizeof(product), sizeof(product), prodcmp_description);
		fwrite(prods, sizeof(product), l / sizeof(product), f);
		break;
	}
	default:
		raise_val_error("You have to inputed numbers 1-4");
	}

	fclose(f);
	free(prods);
	return 0;
}

void fjoin_prod(FILE *f, product *p, int n) { //makes array from products from file

	product prod;
	for (int i = 0; i < n; i++) {
		freadProduct(&prod, f);
		p[i] = prod;
	}
}

int prodcmp_name(const product *prod1, const  product *prod2) {
	char tmp1[15]; strcpy(tmp1, prod1->name); //create buffers for keeping the register, because func _strlwr make all  chars in low 
	char tmp2[15]; strcpy(tmp2, prod2->name);

	int compare = strcmp(_strlwr((prod1->name)), _strlwr(prod2->name));
	strcpy(prod1->name, tmp1); strcpy(prod2->name, tmp2);
	return(compare);
}
int prodcmp_country(const product *prod1, const product *prod2) {
	char tmp1[15]; strcpy(tmp1, prod1->export_ctr); //create buffers for keeping the register, because func _strlwr make all  chars in low 
	char tmp2[15]; strcpy(tmp2, prod2->export_ctr);

	int compare = strcmp(_strlwr((prod1->export_ctr)), _strlwr(prod2->export_ctr));
	strcpy(prod1->export_ctr, tmp1); strcpy(prod2->export_ctr, tmp2);
	return(compare);
}
int prodcmp_description(const product *prod1, const product *prod2) {
	char tmp1[15]; strcpy(tmp1, prod1->description); //create buffers for keeping the register, because func _strlwr make all  chars in low 
	char tmp2[15]; strcpy(tmp2, prod2->description);

	int compare = strcmp(_strlwr((prod1->description)), _strlwr(prod2->description));
	strcpy(prod1->description, tmp1); strcpy(prod2->description, tmp2);
	return(compare);
}
int prodcmp_price(const product *prod1, const product *prod2) {
	return((prod1->price - prod2->price));
}
