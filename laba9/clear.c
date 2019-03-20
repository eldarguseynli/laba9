 #include "tools_9.h"

void clear(void) //func clears stdin buffer
{
	char c = 1;
	while (c = getchar() != '\n' && c != EOF);
}