#include "tools_9.h"

void getClearly(char *buf, int n) {
	fgets(buf, n, stdin); if (strlen(buf) == n - 1 && buf[n - 2] != '\n') clear();
} 