#include "tools_9.h"

int matchStrPar(char *param0, char *param1);
int matchDoublePar(double *param0, double *param1);
int matchProduct(char* name0, char* name1, char *description0, char *description1, char *export_ctr0, char *export_ctr1, double *price0, double *price1);

int findThePlaceOfNote(FILE *f) { //if product matches to the request, place the carriage after this product 
								  //and return the index of next product, else return 0

	char name[15], description[15], export_ctr[15]; double price;

	readParam("Name", name, 14);
	readParam("Description", description, 14);
	readParam("Country, which is exported", export_ctr, 14);
	printf("Price:"); readDoubleClearly(&price);

	product prod; int i = 0;
	while (!feof(f)) {
		freadProduct(&prod, f);
		if (!feof(f))
		{
			i++;
			if (matchProduct(name, prod.name, description, prod.description, export_ctr, prod.export_ctr, &price, &prod.price)) {
				fseek(f, -(int)sizeof(product), SEEK_CUR); return i;
			}
		}
	}
	return 0;
}

int matchStrPar(char *param0, char *param1) {
	if (!param0[0]) return 1;              //param0 is param which user has inputed //if user inputed empty string - ignor this param
	if (strcmp(param0, param1)) return 0;
	else return 1;
}
int matchDoublePar(double *param0, double *param1) { //if it matches return 1
	if (*param0 < 0 || *param0 == *param1) return 1;	 //if user inputed negative number - ignor price
	else return 0;
}
int matchProduct(char* name0, char* name1, char *description0, char *description1, char *export_ctr0, char *export_ctr1, double *price0, double *price1) {
	return (matchStrPar(name0, name1) && matchStrPar(description0, description1) && matchStrPar(export_ctr0, export_ctr1) && matchDoublePar(price0, price1));
	//match all param
}
