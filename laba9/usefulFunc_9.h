#pragma once

#include "product.h"
#include "tools_9.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int createFile(char *name, int n);
int deleteTheNote(char *name);
product* findTheNote(char *name, product *buf);
int editTheNote(char *name);
int sortTheNotes(char *name);
int outputTheNotes(char *name);