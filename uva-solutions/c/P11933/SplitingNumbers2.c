/**
 * Author: Miguel Tomé
 * Purpose: Crete a program to solve the problem 11933 from UVA
 *  This program should read numbers from the console and split them by is binary
 * Date: 21-09-2020
 */

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

/**
 * This function will split the number by its binary, considering the even 1's 
 * from the LSB
 * number is the number to split
 * return the splited number
 */
int splitNumber(int number) {
    
    int i = 0; /* the index of the binary */ 
    int c = 0; /* number of 1's founded */
    int splitedNumber = 0;

    while(number != 0) {
        if (number % 2) {
            if (c++ % 2 == 0) { /* consider only the even 1's */
                splitedNumber += pow(2, i);
            }
        }
        i++;
        number /= 2;
    }
    return splitedNumber;
}

int main() {
    int n; /* the number to split */
    while (scanf("%d", &n) == 1 && n) {
        int splidedNumber = splitNumber(n);
        printf("%d %d\n", splidedNumber, n-splidedNumber);
    }
    return 0;
}