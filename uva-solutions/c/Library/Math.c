/**
 * Author: Miguel Tomé
 * Purpose: This file have the purpose of having some common and useful functions
 *  that are not available on standard lybrary of c.
 * 
 *      TODO
 *      - improve the generate primes function (legibility)
 *      - create a vertion that do not use memory (not so fast, but go longer than 10^7)
 *      - create a function that give to use the n first primes
 * 
 * Date: 01-10-2020
 */

#include <math.h>
#include <stdio.h>
#include <stdbool.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

#define MAX_PRIMES 10000000

/**
 * This function calculates the max number of primes under a certain number (maxPrime).
 * We use an aproximation N = X / ln (X - 1). 
 * 
 * @param maxPrime is the biggest prime
 * @return the number of primes under maxPrime
 */
int maxNumberOfPrimes(int maxPrime) {
    
    int n; /* number of primes aproximatelly above maxPrime */
    n = maxPrime / log((double)(maxPrime - 1)); /* log is the ln well known function with base e */

    n *= 1.2; /* increase 20% to give some insurance */

    return n;
}

/**
 * This function checks if a given number is prime
 * 
 * @param primes and array with the current list of primes
 * @param number the number to verify if is prime
 * @return true if the number is prime, false otherwise
 */
bool isPrime(int *primes, int number) {

    int i;
    for (i = 0; primes[i] * primes[i] <= number; i++) {

        if (number % primes[i] == 0) {
            return false; /* if is not prime number */
        }
    }

    return true;
} 

/**
 * This function will generate the primes under or equal maxPrime.
 * 
 * @param primes an array to store the primes
 * @param maxPrimes is the biggest prime to find (maxPrime > 3)
 * @return number of primes
 */
int genPrimes(int *primes, int maxPrime) {

    int n = 2; /* the number os existing primes under maxPrime */

    primes[0] = 2;
    primes[1] = 3;
    
    int i;
    for (i = 5; i <= maxPrime; i += 2) {

        if (isPrime(primes, i)) { /* not exited from break inside the loop above */
            primes[n++] = i;
        }
    }

    return n;
}

int main() {

    int i;
    for (i = 10; i <= MAX_PRIMES; i *= 10) {

        int maxPrimes; 
        maxPrimes = maxNumberOfPrimes(i);

        int primes[maxPrimes];

        int n; /* the number of primes under MAX_PRIME */
        n = genPrimes(primes, i);

        printf("UNDER %d: %d / %d\n", i, n, maxPrimes);
    }

    return 0;
}