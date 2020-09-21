/**
 * Author: Miguel Tomé
 * Purpose: Crete a program to solve the problem 11933 from UVA
 *  This program should read numbers from the console and split them by is binary
 * Date: 21-09-2020
 */

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define BINARY_MAX_SIZE 32

bool binNumber[BINARY_MAX_SIZE];

void decimalToBinary(int number) {
    int i;
    for (i = 0; i < BINARY_MAX_SIZE; i++) {
        binNumber[i] = 0;
    }

    i = 0;
    while(number != 0) {
        binNumber[BINARY_MAX_SIZE - i++ -1] = number % 2;
        number /= 2;
    }
}

int binaryToDecimal(bool *part) {
    int number = 0;
    int i;
    for (i = BINARY_MAX_SIZE - 1; i >= 0; i--) {
        number += part[i] * pow(2, BINARY_MAX_SIZE - i - 1);
    }
    return number;
}

/**
 * This method splits the binNumber[] into two parts
 * takeFirstBit is a flag that tell us to consider the first 1 from LSB
 * return the decimal representation of the part
 */
int splitBinNumber(bool takeFirstBit) {

    bool part[BINARY_MAX_SIZE];

    /* initialize */
    int i;
    for (i = 0; i < BINARY_MAX_SIZE; i++) {
        part[i] = 0;
    }

    for (i = BINARY_MAX_SIZE - 1; i >= 0; i--) {
        if (binNumber[i]) {
            if (takeFirstBit) {
                part[i] = 1;
                takeFirstBit = false;
            }
            else {
                takeFirstBit = true;
            }
        }
    }

    return binaryToDecimal(part);
}

void splitNumber(int number) {
    
    decimalToBinary(number);
    int a = splitBinNumber(true); /* split the number considering the first one at binary */
    int b = splitBinNumber(false); /* doesnt consider the first one at binary */

    printf("%d %d\n", a, b);
}

int main() {
    int n; /* the number to split */
    while (scanf("%d", &n) == 1 && n) {
        splitNumber(n);
    }
    return 0;
}