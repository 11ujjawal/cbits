#ifndef _CBITS_H
#define _CBITS_H

/* Data Structure for storing the bit pattern */
typedef struct cbits {

    /* Number of bits in array */
    size_t bitsize;

    /* Pointer to array containing bits */
    unsigned char data[];

} cbits;


/* Function Prototypes */

/* Create / Destroy functions */
char* bitnew(const char *bitArray);
int bitfree(const char *bitArray);

/* Bit manipulation functions */
static int bitinorder(const char *bitArray, size_t bitlen);
size_t bitlen(const char *bitArray);

#endif
