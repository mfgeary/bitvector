#include <stdio.h>
#include <stdlib.h>

#include "bitvector.h"

// Marion Geary
// Wheaton College, Fall 2021
// November 2, 2021


// Print all values based on the size of the vector using set formatting
void
printVec(struct bit_vector *vec)
{
	int isFirst, i;
	printf("{");
	isFirst = 1;
	int num = vec -> size;
	for (i = 0; i <= num; i++)
		if (bv_contains(vec, i)) {
			if (!isFirst)
				printf(", ");
			printf("%d", i);
			isFirst = 0;
		}
	printf("} \n");
}

int
main(void)
{
        int n, i, j, k;
	struct bit_vector *vec;

	// Get max set value from user
	printf("Enter max int-> ");
	scanf("%d", &n);

	// Create bit vector
	vec = bv_create(n + 1);

	// Fill bit vector will all values
	for (k = 2; k <= n; k++) {
	        bv_insert(vec, k);
	}

	// Find all primes by removing all multiples of each value
	for (i = 2; i <= n/2; i++) {
	        for (j = i + 1; j <= n ; j++) {
	                // Remove all multiples of i
	                if (j % i == 0) {
	                        bv_remove(vec, j);
	                }
	        }
	}

	printf("vec = ");
	printVec(vec);

	bv_destroy(vec);
	return 0;
}
