#ifndef _CBITS_H
#define _CBITS_H

/* Data Structure for storing the bit pattern */
typedef struct cbits;

/* Function Prototypes */

/* Create / Destroy functions */
char* bitnew(const char *);
int bitfree(cbits*);

size_t bitlen(const char *);

#endif
