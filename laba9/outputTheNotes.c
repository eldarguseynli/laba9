#include "usefulFunc_9.h"

int outputTheNotes(char *name) {
	FILE *f;
	fopenCorrectly(&f, name, "r+b");
	puts("\n--------------------------------TABLE-OF-DATA----------------------------------\n");
	puts("Name             Description                 Where is exported           Price\n");
	product prod;
	while (!feof(f))
	{
		freadProduct(&prod, f);
		if (!feof(f))
		{
			printf("%s", prod.name); printMultStr(17 - strlen(prod.name), " ");				  //print so mush blackspaces as we need to assign the tables, 17 and
			printf("%s", prod.description); printMultStr(28 - strlen(prod.description), " "); //other numbers because it is the length between the tables
			printf("%s", prod.export_ctr); printMultStr(28 - strlen(prod.export_ctr), " ");
			printf("%.2lf\n\n", prod.price);
		}
	}
	puts("-------------------------------------------------------------------------------");
	fclose(f);
}