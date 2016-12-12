#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

bool isPowerOfTwo(int num);
bool all(int num);
bool sign(int numOne, int numTwo);
char* print(bool result);

int main(void) {
    /* Four integers numZero, numEven, numOdd, numPowerTwo are define each
     * initialized to the prefixed value.
     */
    int numAll = 255,           /* 0000 0000 1111 1111 */
        numZero = 0,            /* 0000 0000 0000 0000 */
        numOdd = 23,            /* 0000 0000 0001 0111 */
        numEven = 362,          /* 0000 0001 0110 1010 */
        numNeg = -361,          /* 1111 1110 1001 0111 */
        numPowerTwo = 512;      /* 0000 0010 0000 0000 */

    /* Demonstrates-> isPowerOfTwo() */
    printf("\nisPowerOfTwo()\n");
    printf("\t%d -> %s", numOdd, print(isPowerOfTwo(numOdd)));
    printf("\t%d -> %s", numPowerTwo, print(isPowerOfTwo(numPowerTwo)));

    /* Demonstrates-> all() */
    printf("\nall()\n");
    printf("\t%d -> %s", numAll, print(all(numAll)));
    printf("\t%d -> %s", INT_MAX, print(all(INT_MAX)));
    printf("\t%d -> %s", numOdd, print(all(numOdd)));

    /* Demonstrates sign() */
    printf("\nsign()\n");
    printf("\t%d, %d -> %s", numEven, numNeg, print(sign(numEven, numNeg)));
    printf("\t%d, %d -> %s", numEven, numOdd, print(sign(numEven, numOdd)));
    printf("\t%d, %d -> %s", numNeg, numNeg, print(sign(numNeg, numNeg)));


    return 0;
}

/* To check if a number is power of two.
 * Bitwise AND the given number and the number one less than the given number
 * and equate the result to zero. A number which is a power of 2, will be
 * reduced to zero after the operation.
 *
 * CAUTION - The below method will work for unsigned numbers only because the
 * numbers are stored as two's complement in the computer memeory.
 * Ex. -512 will be stored as: 1111 1110 0000 0000
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

/* To check if the number is of the form (2^n - 1), 0 or all 1s.
 * Bitwise AND of the given number and one more than the given number toggle the
 * trailing set bits and its equation to zero is truth if the number is in the
 * above listed form.
 *
 * CAUTION - The below method will work for unsigned numbers only because the
 * numbers are stored as two's complement in the computer memeory.
 * Ex. -512 will be stored as: 1111 1110 0000 0000
 *
 * Example (numAll + 1): 0000 0001 0000 0000
 * Therefore (0000 0000 1111 1111 & 0000 0001 0000 0000) = 0000 0000 0000 0000
 */
bool all(int num) {
    if(num & (num + 1))
        return false;
    else
        return true;
}

/* Check if two numbers have opposite sign.
 * The MSB or the Sign Bit is set in a negative number and its bitwise XOR will
 * leave the MSB set if the other number is positive (since the MSB of a positive
 * number is unset). Hence, XOR of a positive and a negative number will fetch
 * a negative number.
 *
 * Example -
 *           numNeg -> 1111 1110 1001 0111 (-361)
 *          numEven -> 0000 0001 0110 1010 (362)
 * numNeg ^ numEven -> 1111 1111 1111 1101 (-3)
 */
bool sign(int numOne, int numTwo) {
    if((numOne ^ numTwo) < 0)
        return true;
    else
        return false;
}

/* Preety Print the boolean value */
char* print(bool result) {
    if(result)
        return "TRUE\n";
    else
        return "FALSE\n";
}
