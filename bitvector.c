#include <stdlib.h>
#include <stdio.h>

#include "bitvector.h"

// Marion Geary
// Wheaton College, Fall 2021
// October 30, 2021

// Create the vector and allocate memory
struct bit_vector *
bv_create(int size)
{
        struct bit_vector *bv = malloc(sizeof(struct bit_vector));
        bv -> size = size;
        bv -> vector = malloc(numBytes(bv));
        return bv;
}

// Destory the vector and free the memory
void
bv_destroy(struct bit_vector *v)
{
        v->vector = NULL;
        free(v->vector);
        v = NULL;
        free(v);
}

// Indicate whether the bit_vector contains desired int
int
bv_contains(struct bit_vector *v, int i)
{
        int byte = i / 8;
        int bit = i % 8;
        unsigned char val = (v -> vector)[byte];
        val = (1 << bit) & val;
        if (val | 0)
                return 1;
        return 0;
}

// Insert the desired int into the given bit_vector.
void
bv_insert(struct bit_vector *v, int i)
{
        int byte = i / 8;
        int bit = i % 8;
        unsigned char val = (v -> vector)[byte];
        val = ((1 << bit) | val);
        (v -> vector)[byte] = val;
}

// Remove the given int from the given bit_vector
void
bv_remove(struct bit_vector *v, int i)
{
        int byte = i / 8;
        int bit = i % 8;
        unsigned char val = (v -> vector)[byte];
        val  = (~(1 << bit)) & val;
        (v -> vector)[byte] = val;
}

// Compute the set complement of the given bit_vector. Given bit_vector
// remains unchanged. Returns pointer to new bit_vector representing
// the complement
struct bit_vector *
bv_complement(struct bit_vector *v)
{
        struct bit_vector *bv = malloc(sizeof(*v));
        *bv = *v;
        bv -> vector = malloc(sizeof(v -> vector));
        *(bv -> vector) = *(v -> vector);
        int iterations = numBytes(bv);
        int i;
        for (i = 0; i <= iterations; i++) {
                unsigned char val = (bv -> vector)[i];
                (bv -> vector)[i] = ~val;
        }
        return bv;
}

// Return the number of bytes contained in a given bit vector
int
numBytes(struct bit_vector *v)
{
        int size = v -> size;
        return (size / 8);
}

// Compute the set union (A U B) of two given bit vectors. The given vectors
// remain unchanged. Returns a pointer to a new bit vector representing the
// union
struct bit_vector *
bv_union(struct bit_vector *v1, struct bit_vector *v2)
{
        int num1 = numBytes(v1);
        int num2 = numBytes(v2);
        struct bit_vector *bv = malloc(sizeof(v1) + sizeof(v2));
        bv -> vector = malloc(sizeof(v1 -> vector) + sizeof(v2 -> vector));
	
        int its, i;
        if (num1 >= num2)
                its = num1;
        else
                its = num2;
	
        for (i = 0; i <= its; i++) 
                (bv -> vector)[i] = ((v1 -> vector)[i] | (v2 -> vector)[i]);
       return bv;
}

// Compute the set intersection (A ∩ B) of two given bit vectors. The given
// vectors remain unchanged. Returns pointer to a new bit vector representing
// the intersection.
struct bit_vector *
bv_intersection(struct bit_vector *v1, struct bit_vector *v2)
{
        int num1 = numBytes(v1);
        int num2 = numBytes(v2);
        struct bit_vector *bv = malloc(sizeof(v1) + sizeof(v2));
  
        int its, i;
        unsigned char *store;
        if (num1 <= num2) {
                its = num1;
                store = v1 -> vector;
        } else {
                its = num2;
                store = v2 -> vector;
        }
        bv -> vector = malloc(sizeof(store));
 
        for (i = 0; i <= its; i++) {
                unsigned char *ret1 = v1 -> vector;
                unsigned char *ret2 = v2 -> vector;
                (bv -> vector)[i] = (ret1[i] & ret2[i]);
        }
        return bv;

}


// Compute the set difference of the given sets (A - B). The given sets remain
// unaltered. Returns a pointer to a new bit vector representing the set
// difference
struct bit_vector *
bv_difference(struct bit_vector *v1, struct bit_vector *v2)
{
        int num1 = numBytes(v1);
        int num2 = numBytes(v2);
        struct bit_vector *bv = malloc(sizeof(v1));
	
        int its, i;
        unsigned char *store;
        if (num1 <= num2) {
                its = num1;
                store = v1 -> vector;
        } else {
                its = num2;
                store = v2 -> vector;
        }
        bv -> vector = malloc(sizeof(store));
	
        for (i = 0; i <= its; i++) 
                (bv -> vector)[i] = ((v1 -> vector)[i] &  ~((v1 -> vector)[i] & (v2 -> vector)[i]));
        return bv;
}
