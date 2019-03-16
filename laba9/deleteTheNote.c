
#include "usefulFunc_9.h"

int deleteTheNote(char *name) {
	puts(name);
	FILE *f;
	fopenCorrectly(&f, name, "a+b");
	fclose(f);
	puts("Inputs the paramets of note you want to delete");
	if (!findThePlaceOfNote()) { puts("There are no such notes."); system("pause"); return -1; }//return  -1 if we could not delete note
	
}