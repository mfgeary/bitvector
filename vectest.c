#include <stdlib.h>
#include <stdio.h>

#include "bitvector.h"

char *
boolToString(int x)
{
	return x ? "yes" : "no";
}

void
printVec(struct bit_vector *vec)
{
	int isFirst, i;
	printf("{");
	isFirst = 1;
	for (i = 0; i < 10; i++)
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
	int i;
	struct bit_vector *vec = bv_create(10);

	printf("3C vec = ");   
	printVec(vec);



	bv_insert(vec, 5);

	printf("3Di vec = ");
	printVec(vec);

	bv_insert(vec, 9);

	printf("3Dii vec = ");
	printVec(vec);

	bv_remove(vec, 4);

	printf("3Ei vec = ");
	printVec(vec);


	bv_remove(vec, 5);

	printf("3Eii vec = ");
	printVec(vec);

	bv_insert(vec, 0);
	bv_insert(vec, 3);
	bv_insert(vec, 7);

	printf("4Ai vec = ");
	printVec(vec);

	struct bit_vector *vec2 = bv_complement(vec);

	printf("4Aii vec = ");
	printVec(vec);

	printf("4Aiii vec2 = ");
	printVec(vec2);



	bv_remove(vec2, 5);
	bv_remove(vec2, 8);
	bv_insert(vec2, 3);
	bv_insert(vec2, 9);

	printf("4Bi vec = ");
	printVec(vec);
	printf("4Bii vec2 = ");
	printVec(vec2);

	struct bit_vector *vec3 = bv_union(vec, vec2);

	printf("4Biii vec3 = ");
	printVec(vec3);



	printf("4Ci vec = ");
	printVec(vec);
	printf("4Cii vec2 = ");
	printVec(vec2);


	struct bit_vector *vec4 = bv_intersection(vec, vec2);

	printf("4Ciii vec4 = ");
	printVec(vec4);



	printf("4Di vec = ");
	printVec(vec);

	printf("4Dii vec2 = ");
	printVec(vec2);

	struct bit_vector *vec5 = bv_difference(vec, vec2);

	printf("4Diii vec5 = ");
	printVec(vec5);

	bv_destroy(vec5);
	bv_destroy(vec4);
	bv_destroy(vec3);
	bv_destroy(vec2);
	bv_destroy(vec);

	return 0;
}
