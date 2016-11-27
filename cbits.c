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
    unsigned char *data;

} cbits;

/*
 * Create a new cbit object from a null terminating C string
 */
char* bitnew(const char *bit) {
    size_t bitlen = (bit == NULL) ? 0 : strlen(bit);

    cbits *cb = malloc(sizeof(cbits));

    /* If memory allocation fails, set errno to indicate unavailability of
     * space and termiate the call */
    if(cb == NULL) {
        errno = ENOMEM;
        return NULL;
    }

    cb->bitsize = bitlen;
    cb->data = malloc(sizeof(unsigned char) * bitlen);

    /* If memory allocation fails, set errno to indicate unavailability of
     * space and termiate the call */
    if(cb->data == NULL) {
        errno = ENOMEM;
        return NULL;
    }

    /* Check whether the string passed is either 0 or 1. If it is, then copy
     * the value to the cbits object else flag an error for unavailibilty of
     * message of desired type and exit the function returing NULL */
    for(int i = 0; i < bitlen; i++) {
        if(bit[i] == '0' || bit[i] == '1') {
            cb->data[i] = bit[i];
        } else {
            errno = EINVAL;
            free(cb->data);
            free(cb);
            return NULL;
        }
    }
    cb->data[bitlen] = '\0';
    printf("%d\n", cb);
    printf("%d\n", cb + sizeof(size_t));
    printf("%p\n", *cb);

    return cb->data;
}

/*
 *
 */
size_t bitlen(const char *bit) {
    if(bit == NULL)
        return INT_MIN;

    printf("%d\n", bit);

    return 0;
}

int main(void) {
    // char *bit = bitnew("002394");
    // if(bit == NULL) {
    //     printf("%s\n", strerror(errno));
    // }

    char *bit1 = bitnew("01");
    // if(bit1 == NULL) {
    //     printf("%s\n", strerror(errno));
    // } else {
    //     printf("%s\n", bit1);
    // }
    size_t len = bitlen(bit1);
    // printf("%d\n", len);
    return 0;
}
