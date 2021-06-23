#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "prototypes.h"

int* derivative(int* arr, int deg, int deriv, int module) {
	int coef = deg;
	while (deriv != 0) {
		for (int i = 0; i <= coef; i++) {
			arr[i] *= deg;
			mod(&arr[i], &module);
			deg--;
		}
		coef--;
		deg = coef;
		deriv--;
	}
	return arr;
}

int input_valid() {
	int num;
	if ((scanf("%d", &num) != 1) || num < 0) {
		printf("Incorrect input!");
		exit(1);
	}
	return num;
}

void mod(int* num, int* module) {
	while (*num < 0) {
		*num += *module;
	}
	*num %= *module;
}


int isPrime(int* number) {
	if (*number <= 1) {
		printf("Incorrect input!");
		exit(1);
	}
	for (int i = 2; i < *number; i++) {
		if (*number % i == 0) {
			printf("Incorrect input!");
			exit(1);
		}
	}
}