#include "tools_9.h"


int matchStrPar(char *param0, char *param1);
int matchDoublePar(double param0, double param1);
int matchProduct(char* name, char *description, char *export_ctr, double price);

int findThePlaceOfNote(void) {

	//puts("Inputs the paramets of note which you want to delete");
	char name[15], description[15],  export_ctr[15]; double price;

	readParam("Name", name, 14);
	readParam("Description", description, 14);
	readParam("Country, which is exported", export_ctr, 14);
	readDoubleParam("Price", &price);

	matchProduct(name, description, export_ctr, price);

}
//DECLARATION
//think how to allocate the parametrs //think about static memory for names
//if parametr is empty => do not take it in the account
int matchStrPar(char *param0, char *param1) {
	if (!param0[0]) return 1;
	if (strcmp(param0, param1)) return 0;  //CHECH COULD YOU USE SUCH CONDTIONS?
	else return 1;
}
int matchDoublePar(double param0, double param1) { //if it matches return 1
	if (param0 < 0 && param0 == param1) return 1;
	else return 0;
}
int matchProduct(char* name, char *description, char *country, char *export_ctr, double price) {
	
	//read with help of file with loop
	//func whould retrurn 0 , if hadn`t found and 1 if had found
	//the aim of fucn is to place carriage(каретка) in the place where we have found needed product
	//do not forget to close the file
	//you should come back on 1 step in file
}
