#include "usefulFunc_9.h"

int deleteTheNote(char *name) {

	FILE *f; int i;
	fopenCorrectly(&f, name, "r+b"); 

	puts("Input the paramets of product you want to edit in the database\n");
	if (!(i = findThePlaceOfNote(f))) { puts("There are no such notes."); system("pause"); return -1; }//return  -1 if we could not delete note
	fseek(f, sizeof(product), SEEK_CUR);

	product prod;
	while (!feof(f)) {
		freadProduct(&prod, f);
		if (!feof(f))
		{
			i++;
			fseek(f, -2 * (int)sizeof(product), SEEK_CUR);
			fwrite(&prod, sizeof(product), 1, f);
			fseek(f, sizeof(product), SEEK_CUR);
		}
	}
	chsize(_fileno(f), (i - 1) * sizeof(product));
	fclose(f);
	return 0;
}