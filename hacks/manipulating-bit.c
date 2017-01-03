#include <stdio.h>

int main(void) {
    int numOne = 271,
        numTwo = 212,
        numBitSet = -1,
        numBitOne = 1,
        posOne = 5,
        posTwo = 8;

    /* To turn off the rightmost one bit -> num & (num - 1)
     * Example -
     *                  numOne: 0000 0001 0000 1111 (271)
     *              numOne - 1: 0000 0001 0000 1110 (270)
     *  numOne & (numOne - 1) : 0000 0001 0000 1110 (270)
     */
    printf("Turning off the rightmost one bit of %d yields %d\n", numOne, numOne & (numOne - 1));

    /* To turn on the rightmost zero bit -> num | (num + 1)
     * Example -
     *                numOne: 0000 0001 0000 1111 (271)
     *          (numOne + 1): 0000 0001 0001 0000 (272)
     * numOne | (numOne + 1): 0000 0001 0001 1111 (287)
     */
    printf("Turning off the rightmost zero bit of %d yields %d\n", numOne, numOne | (numOne + 1));

    /* To turn off trailing ones -> num & (num + 1)
     * Example -
     *                numOne: 0000 0001 0000 1111
     *          (numOne + 1): 0000 0001 0001 0000
     * numOne & (numOne + 1): 0000 0001 0000 0000
     */
    printf("Turning off trailing ones of %d yields %d\n", numOne, numOne & (numOne + 1));

    /* To turn on trailing zero bits -> num | (num - 1)
     * Example -
     *                  numTwo: 0000 0000 1101 0100 (212)
     *              numTwo - 1: 0000 0000 1101 0011 (211)
     *  numTwo | (numTwo - 1) : 0000 0000 1101 0111 (215)
     */
    printf("Turning on trailing zeros of %d yields %d\n", numTwo, numTwo | (numTwo - 1));

    /* Compute the union of two bit patterns
     * Example -
     *                  numOne: 0000 0001 0000 1111 (271)
     *                  numTwo: 0000 0000 1101 0100 (212)
     *         numOne | numTwo: 0000 0001 1101 1111 (479)
     */
    printf("Union of bit patterns of %d and %d yields %d\n", numOne, numTwo, numOne | numTwo);

    /* Compute the intersection of two bit patterns
     * Example -
     *                  numOne: 0000 0001 0000 1111 (271)
     *                  numTwo: 0000 0000 1101 0100 (212)
     *         numOne & numTwo: 0000 0000 0000 0100 (4)
     */
    printf("Intersection of bit patterns of %d and %d yields %d\n", numOne, numTwo, numOne & numTwo);

    /* Subtract one bit pattern from another
     * Example -
     *                  numOne: 0000 0001 0000 1111 (271)
     *                  numTwo: 0000 0000 1101 0100 (212)
     *                 ~numTwo: 1111 1111 0010 1011 (212)
     *        numOne & ~numTwo: 0000 0001 0000 1011 (267)
     */
    printf("Subtracting bit pattern of %d from %d yields %d\n", numOne, numTwo, numOne & ~numTwo);

    /* Compute the inverse of the given bit pattern
     * Example -
     *                  numOne: 0000 0001 0000 1111 (271)
     *               numBitSet: 1111 1111 1111 1111 (-1)
     *      numBitSet ^ numOne: 1111 1110 1111 0000 (-272)
     */
    printf("Inverse of bit pattern of %d yields %d\n", numOne, numBitSet ^ numOne);

    /* Set a bit in a given bit pattern
     * Example -
     *                           numOne: 0000 0001 0000 1111 (271)
     *                        numBitOne: 0000 0000 0000 0001 (1)
     *              numBitOne << posOne: 0000 0000 0010 0000 (1 << 5 -> 32)
     *     numOne | numBitOne << posOne: 0000 0000 0010 0000 (303)
     */
    printf("Setting the 5th bit of %d yields %d\n", numOne, numOne | (numBitOne << posOne));

    /* Clear a bit in a given bit pattern
     * Example -
     *                           numOne: 0000 0001 0000 1111 (271)
     *                        numBitOne: 0000 0000 0000 0001 (1)
     *              numBitOne << posTwo: 0000 0001 0000 0000 (1 << 8 -> 256)
     *             ~numBitOne << posTwo: 1111 1110 1111 1111 (-257)
     *  numOne & ~(numBitOne << posTwo): 0000 0000 0010 1111 (15)
     */
    printf("Clearing the 8th bit of %d yields %d\n", numOne, numOne & ~(numBitOne << posTwo));

    return 0;
}
