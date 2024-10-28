#include <stdio.h>

/*
    Return the n-th bit of the given 32-bit value
    Example: value = 13 (1101), n = 2 => returns 1
    Example: value = 13 (1101), n = 1 => returns 0
    Example: value = 13 (1101), n = 12 => returns 0
 */

int get_bit(unsigned int value, int n) { return !!(value & (1 << n)); }
int get_bit1(unsigned int value, int n) { return (value >> n) & 1; }

/*
    Modify n-th bit of given 32-bit value to 'bit' and return the modified 32-bit value
    Example: value = 13 (1101), n = 2, bit = 1 => returns 13 (1101)
    Example: value = 13 (1101), n = 1, bit = 1 => returns 15 (1111)
    Example: value = 13 (1101), n = 2, bit = 0 => returns  9 (1001)
 */

int modify_bit(int value, int n, int bit) { return (bit << n) | ((~(1 << n)) & value); }

/*
    Gets two 32-bit values, a and b, returns a new value whose
    odd bits come from a, and even bits come from b
 */

int odd_even(int a, int b) {
    int maschera = 0b01010101010101010101010101010101;
    return (a & maschera) | (b & (~maschera));
}

int main() {
    int a, b, c;

    a = get_bit(13, 2);
    b = modify_bit(13, 2, 0);
    c = odd_even(10, 3);

    printf("a: %d - b: %d - c: %d\n", a, b, c);

    return 0;
}