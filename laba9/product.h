#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
	char name[15];
	char description[15];
	char export_ctr[15];
	double price;
}product;

int freadProduct(product *p, FILE *f);