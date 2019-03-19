#pragma once

#include "product.h"
#include "tools_9.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int createFile(char *name);
int addTheNote(char *name);
int deleteTheNote(char *name);
int findTheNote(char *name);
int editTheNote(char *name);
int sortTheNotes(char *name);
int outputTheNotes(char *name);