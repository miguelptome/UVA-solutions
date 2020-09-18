/**
 * Author: Miguel Tomé
 * Purpose: Calculate the prime numbers between 1..N
 *  . calculate a cut in the middle of the prime numbers list, that is also a list
 *  . and vary if the list od primes is even or odd
 *  . cut of 2C if the list is even 
 *  . cut of 2C-1 otherwise
 * Date: 18-09-2020
 */

#include <stdio.h>
#include <stdbool.h>

#define MAX_PRIME 1000

int primesc = 1; /* number of primes */
int primes[MAX_PRIME + 1] = {1};

/**
 * Validate if a given number if prime
 * number is the number to validate
 */
bool isPrime(int number) {
    if (number < 1) {
        return false;
    }

    int i;
    for (i = 2; i*i <= number; i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

/**
 * generate an array of primes, that is stored as global at primes[]
 * and the total of primes numbers will be stored alsa as global at primec
 * On this particular implementation the number 1 is considered as prime
 */
void genPrimes() {
    int i;
    for (i = 2; i <= MAX_PRIME; i++) {
        if (isPrime(i)) {
            primes[primesc++] = i;
        }
    }
} 

/**
 * Calculate the number of primes under a given number
 * n is the biggest prime to consider inclusive
 */
int underPrimes(int n) {

    if (n >= primes[primesc - 1]) {
        return primesc;
    }

    int i;
    for (i = 0; i < primesc; i++) {
        if (primes[i] > n) {
            return i;
        }
    }
    return 0;
}

/**
 * make a cut on primes list
 * n is the number of primes to consider
 * c is the cut factor to calculate cut size
 */
void cutPrimes(int n, int c) {

    /* calculate the cut size */
    int cutSize;
    if (n % 2 == 0) {
        cutSize = 2*c;
    }
    else {
        cutSize = 2*c - 1;
    }

    /* calculate de begining index of the cut */
    int cutCenterIndex = n / 2;
    int cutBeginIndex = cutCenterIndex - (cutSize / 2);

    /* case when the cut is greater than the list */
    if (cutSize > n) {
        cutBeginIndex = 0;
        cutSize = n;
    }

    /* print the cut of the primes */
    int i;
    for (i = cutBeginIndex; i < (cutBeginIndex + cutSize); i++) {
        printf(" %d", primes[i]);
    }
}

int main() {

    genPrimes(); /* put the list of primes at the global array primes[] */

    int n, c; /* n is the prime number list limit (1..n) and c is the cut (1 <= c <= n) */

    while (scanf("%d %d", &n, &c) == 2) { /* scanf return the number of inputs readed successful */
        printf("%d %d:", n, c);
        int up = underPrimes(n); /* calculate the number of primes under n */
        cutPrimes(up, c);
        puts("\n");
    }

    return 0;
}