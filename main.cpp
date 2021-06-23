#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "prototypes.h"
int main() {
	int deg = 0, deriv = 0, idx = 0;
	int prime, deg_prime, module = 0;
	float tmp = 0;
	int* arr = NULL;
	printf("Input prime number: ");
	prime = input_valid();
	isPrime(&prime);

	printf("Input degree of the prime number: ");
	deg_prime = input_valid();
	module = prime;
	for (int i = 1; i < deg_prime; i++) {
		module *= prime;
	}
	printf("\nGF(p^r) = GF(%d)\n\n", module);
	printf("Input degree of the polynomial: ");

	if ((scanf("%d", &deg) != 1)) {
		printf("Incorrect input!");
		exit(1);
	}

	mod(&deg, &module);
	printf("\nby module %d is: %d\n", module, deg);
	arr = (int*)malloc((deg + 1) * sizeof(int));
	if (arr == NULL) {
		printf("Allocation error!");
		exit(1);
	}
	printf("\n");

	for (int i = 0; i < (deg + 1); i++) {
		printf("Input %d coefficient: ", (i + 1));
		if ((scanf("%d", &arr[i]) != 1)) {
			printf("Incorrect input!");
			exit(1);
		}
		mod(&arr[i], &module);
	}

	printf("\ncoefficient by module %d\n", module);

	for (int j = 0; j < (deg + 1); j++) {
		printf("%d ", arr[j]);
	}

	tmp = (float)deg / 2;
	deriv = (int)tmp;
	if ((deriv + 0.5) == tmp) {
		deriv += 1;
	}

	printf("\n");

	if (deg == 0) {
		arr[0] = 0;
		printf("1 coefficient: %d", arr[0]);
	}

	else {
		derivative(arr, deg, deriv, module);
		printf("\n");
		for(int i = 0; i <= deg; i++)
			printf("%d coefficient: %d\n", (i + 1), arr[i]);
	}

	free(arr);
	return 0;
}