#include "tools_9.h"

void getClearly(char *buf, int n) {
	fgets(buf, n, stdin); if (strlen(buf) == n && buf[n] != '\n') clear();
}