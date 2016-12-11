#include <stdio.h>

int main(void) {
    int numOne = 271,
        numTwo = 512;

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



    return 0;
}
