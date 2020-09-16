/*
 * Author: Miguel Tomé
 * Purpose: Solution to problem 382 from UVA
 * 
 *  Given a number, determine if it is perfect, abundant or deficient.
 *  - perfect is a positive integer that is equal to the sum of all its positive proper divisors
 *  - deficient if the sum of all its proper integers divisors are smaller than the number
 *  - abundant if the sum of all its proper integers divisors are larger than the number
 *  If a,b,c are integers such as a = bc then a is called a multiple of b or c, and b or c
 *  is called a divisor or a.
 * 
 * Date: 16-09-2020
 */

#include <stdio.h>
#include <math.h>

enum perfection { perfect, abundant, deficient };

/*
 * Evaluate the perfection od a given number
 * number is a positive integer (1 < number < 60000)
 */
enum perfection evaluatePerfection(int number) {

    int i, sum = 1, sq = (int)sqrt(number);

    for (i = 2; i <= sq; i++) {
        if (number % i == 0) { /* its a divisor */
            sum += i + (number/i);
        }
    }

    if (number == 1) {
        return deficient;
    }
    if (sum == number) {
        return perfect;
    }
    if (sum < number) {
        return deficient;
    }
    return abundant;
}

/*
 * Evaluate the perfection od a given number
 * number is a positive integer (1 < number < 60000)
 */
enum perfection evaluatePerfectionBruteForce(int number) {

    int i, sum = 0;

    for (i = 1; i < number; i++) {
        if ((number % i) == 0) { /* its a divisor */
            sum += i;
        }
    }

    if (number == 1) {
        return deficient;
    }
    if (sum == number) {
        return perfect;
    }
    if (sum < number) {
        return deficient;
    }
    return abundant;
}

/*
 * Process output 
 * numbers[] is a list of numbers 
 * numbersEvaluation is a list with the perfections evaluation
 * n is the number of numbers
 */
void printOutput(int numbers[], enum perfection numbersEvaluation[], int n) {
    
    int i;
    
    puts("PERFECTION OUTPUT");
    
    for (i = 0; i < n; i++) {
        
        printf("%5d  ", numbers[i]);

        switch(numbersEvaluation[i]) {
            case perfect:
                puts("PERFECT");
            break;
            case abundant:
                puts("ABUNDANT");
            break;
            case deficient:
                puts("DEFICIENT");
        }
    }

    puts("END OF OUTPUT");
}

int main() {

    int numbers[100];
    enum perfection numbersEvaluation[100];
    int n = 0; /* the number of numbers */

    while (scanf("%d", &numbers[n]) == 1 && numbers[n]) {
        
        n++;
        numbersEvaluation[n-1] = evaluatePerfection(numbers[n-1]);
    }

    printOutput(numbers, numbersEvaluation, n);

    return 0;
}