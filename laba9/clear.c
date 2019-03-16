#include "tools_9.h"

void clear(void) //func clears stdin buffer
{
	char c = 1; //fseek(1, stdin, SEEK_CUR);
	if (!feof(stdin)) while (c = getchar() != '\n' && c != EOF);
	//else fseek(-1, stdin, SEEK_CUR);
}