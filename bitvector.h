#ifndef BIT_VECTOR_H
#define BIT_VECTOR_H

struct bit_vector {
	int size;
	unsigned char *vector;
};

typedef struct bit_vector bit_vector_t;

struct bit_vector *bv_create(int size);

void bv_destroy(struct bit_vector *v);

void bv_insert(struct bit_vector *v, int i);

void bv_remove(struct bit_vector *v, int i);

int bv_contains(struct bit_vector *v, int i);

struct bit_vector *bv_union(struct bit_vector *v1, struct bit_vector *v2);

struct bit_vector *bv_intersection(struct bit_vector *v1, struct bit_vector *v2);

struct bit_vector *bv_difference(struct bit_vector *v1, struct bit_vector *v2);

struct bit_vector *bv_complement(struct bit_vector *v);

int numBytes(struct bit_vector *v);

#endif
