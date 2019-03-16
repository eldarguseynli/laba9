#include "tools_9.h"

int fillFile(FILE *f) //replace from useful...
{
	product prod;

	read_validateParam("Name", prod.name, 14);
	read_validateParam("Description", prod.description, 14);
	read_validateParam("Export_ctr", prod.export_ctr, 14);
	readDoubleParam("Price", &prod.price);

	fwrite(&prod, sizeof(product), 1, f);

	return 0;
}

