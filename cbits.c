#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <stdint.h>
#include <limits.h>


/* Type definition */
typedef struct cbits {

    /* Number of bits in array */
    size_t bitsize;

    /* Pointer to array containing bits */
    unsigned char data[];

} cbits;

/* Check whether the string passed is either 0 or 1. If it is, then copy
 * the value to the cbits object else flag an error for unavailibilty of
 * message of desired type and exit the function returing NULL */
static int bitinorder(const char *bit, size_t bitlen) {
    for(int i = 0; i < bitlen; i++) {
        if(!(bit[i] == '0' || bit[i] == '1')) {
            errno = EINVAL;
            return 0;
        }
    }

    return 1;
}

/*
 * Create a new cbit object from a null terminating C string
 */
char* bitnew(const char *bit) {
    size_t bitlen = (bit == NULL) ? 0 : strlen(bit);

    if(!bitinorder(bit, bitlen)) {
        return NULL;
    }

    /* Assign memory equal to the size of the cbits struct, the number of
     * characters in the bit array and one for null character */
    cbits *cb = malloc(sizeof(cbits) + bitlen + 1);

    /* If memory allocation fails, set errno to indicate unavailability of
     * space and termiate the call */
    if(cb == NULL) {
        errno = ENOMEM;
        return NULL;
    }

    cb->bitsize = bitlen;
    memcpy(cb->data, bit, bitlen);
    cb->data[bitlen] = '\0';

    return cb->data;
}

/*
 * Returns the total number of bits
 */
size_t bitlen(const char *bit) {
    if(bit == NULL)
        return INT_MIN;

    return ((cbits*)(bit - sizeof(size_t)))->bitsize;
}

int main(void) {
    char *bit = bitnew("002394");
    if(bit1 == NULL) {
        printf("%s\n", strerror(errno));
    }

    /* Initialize the bit pattern as sequence of zeros and ones */
    char *bit1 = bitnew("010101");

    /* The bit pattern returns a pointer to the string containing the
     * characters which can be equated to NULL to check if the value
     * has been assigned */
    if(bit1 == NULL) {
        printf("%s\n", strerror(errno));
    } else {
        printf("%s\n", bit1);
    }

    /* Query the total number of bits stored */
    size_t len = bitlen(bit1);
    printf("%d\n", len);

    return 0;
}
