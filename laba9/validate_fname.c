#include "tools_9.h"

int validate_fname(char *name) {
	char unval_symbols[] = { '/', '\\', '?', '%', '*', ':', '|', '"', '<', '>', 0 };
	int i = 0, k; //check that name length is greater than 0
	while (name[i])
	{	
		k = 0;
		while (unval_symbols[k])
		{
			if (name[i] == unval_symbols[k]){
				raise_val_error("You`ve inputed unvalid symbols in name of file.\n\
				Avoid such symbols as  '/', '\\', '?', '%', '*', ':', '|', '\"', '<', '>'. Terminating the programm");
			}
			k++;
		}
		i++;
	}
	if (!i) raise_val_error("The length of file must be greater then 0");
}