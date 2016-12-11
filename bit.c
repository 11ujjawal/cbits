#include <stdio.h>
#include <stdbool.h>

bool isPowerOfTwo(int num);
char* print(bool result);

int main(void) {
    /* Four integers numZero, numEven, numOdd, numPowerTwo are define each
     * initialized to the prefixed value.
     */
    int numZero = 0,            /* 0000 0000 0000 0000 */
        numOdd = 23,            /* 0000 0000 0001 0111 */
        numEven = 362,          /* 0000 0001 0110 1010 */
        numPowerTwo = 512;      /* 0000 0010 0000 0000 */

    printf("Is %d power of 2? %s", numOdd, print(isPowerOfTwo(numOdd)));
    printf("Is %d power of 2? %s", numPowerTwo, print(isPowerOfTwo(numPowerTwo)));
    return 0;
}

/* To check if a number is power of two, toggle the rightmost bit and equate the
 * result to zero. A number which is a power of 2, will be reduced to zero after
 * the operation.
 *
 * Ex. (numPowerTwo - 1): 00000 0001 1111 1111
 * Therefore, (000 0010 0000 0000 & 0000 0001 1111 1111) = 0000 0000 0000 0000
 */
bool isPowerOfTwo(int num) {
    if(num & (num - 1))
        return false;
    else
        return true;
}

/* Preety Print the boolean value */
char* print(bool result) {
    if(result)
        return "TRUE\n";
    else
        return "FALSE\n";
}
