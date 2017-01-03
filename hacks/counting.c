#include <stdio.h>

size_t bitCountNaive(int num);
size_t bitCountBrian(int num);
size_t bitCount64(unsigned int num);

int main(void) {
    int numOne = 3892;

    printf("Total set bits in %d is %d.\n", numOne, bitCountNaive(numOne));
    printf("Total set bits in %d is %d.\n", numOne, bitCountBrian(numOne));

    return 0;
}

/* Naive bit counting approach.
 * Iterate through the number, right shifting it one at a time. Bitwise AND
 * after every iteration with 1, to detect the presence of a set bit on the
 * rightmost bit.
 */
size_t bitCountNaive(int num) {
    size_t count = 0;

    for(size_t i = 0; num; num >>= 1)
        count += num & 1;

    return count;
}

/* Brian Kernighan's way
 * Count the rightmost set bit. The rightmost set bit can be accessed by bitwise
 * AND of the given number and the number one less than the given number.
 */
size_t bitCountBrian(int num) {
    size_t count = 0;

    for(; num; count++)
        num &= num - 1;

    return count;
}
