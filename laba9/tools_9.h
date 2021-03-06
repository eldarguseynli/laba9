#pragma once

#include "product.h"
#include <stdio.h>
#include <string.h>

void fopenCorrectly(FILE **f, char *name, char *mode);
void raise_val_error(char *message);
int validate_fname(char *name);

int findThePlaceOfNote(FILE *f);
int fillFile(FILE *f);
void read_validateParam(char *atr_name, char *param, int n);
void readParam(char *atr_name, char *param, int n);
void readDoubleParam(char *atr_name, double *double_param);

void clear(void);
void getClearly(char *buf, int n);
void readDoubleClearly(double *x);
void readIntClearly(int *n);

void printMultStr(int n, char *str);