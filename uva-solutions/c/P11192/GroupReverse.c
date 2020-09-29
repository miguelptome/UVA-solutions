/**
 * Author: Miguel Tomé
 * Purpose: Create a program to solve the uva challenge 11192. The challenge is
 *  to reverse a string groups. Every string have a certain number of groups that is
 *  given on input
 * Date: 29-09-2020
 */

#include <stdio.h>
#include <string.h>

#define STRING_MAX_LEN 101 /* string to reverse max length */

/**
 * This function will reverse a substring of a string s, from startIndex to endIndex
 * 0 <= startIndex <= endIndex < length(s)
 * return the string s with the subtring reversed
 */
void substringReverse(char *s, int startIndex, int endIndex) {
    
    /**
     * The startegy is to iterate until the middle index and 
     * swap the head and the tail at same distance
     */
    
    int middleIndex = startIndex + ((endIndex - startIndex) / 2);

    int i;
    for (i = startIndex; i <= middleIndex; i++) {

        /* the index of the char to swap for the char at i */
        int ii = endIndex - (i - startIndex); 

        /* swap */
        char aux = s[i];
        s[i] = s[ii];
        s[ii] = aux;
    }
}

/**
 * This function will receive a referenced string to reverse s and number of groups g
 * and reverse each s group. The length of s is multiple of g
 * return void
 */
void stringGroupsReverse(char *s, int g) {

    int len = strlen(s); /* string length */
    int groupSize = len / g;

    int i;
    for (i = 0; i < len; i += groupSize) {

        substringReverse(s, i, i + groupSize - 1);
    }
}

int main() {

    int g; /* the number of groups on the string */
    while(scanf("%d", &g) && g) { /* read until g is equal to zero */

        char s[STRING_MAX_LEN]; /* the string to reverse */
        scanf("%s", &s);

        stringGroupsReverse(s, g);
        puts(s);
    }
    
    return 0;
}