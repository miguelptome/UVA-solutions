/**
 * Author: Miguel Tomé
 * Purpose: This file have the purpose of having some common and useful functions
 *  that are not available on standard lybrary of c.
 * Date: 01-10-2020
 */

#include <stdio.h>

/**
 * This function will reverse a substring of a string s, from startIndex to endIndex
 * Parameters restriction 0 <= startIndex <= endIndex < length(s)
 * 
 *      Example:
        char s[] = "ABCDE";
        reverseSubstring(s, 1, 4);
 *       
 * @param s is the string where the reverse will been applyed
 * @param startIndex is the beginig index on s
 * @param endIndex is the finish index on s
 * @return the string s with the subtring reversed
 */
void reverseSubstring(char *s, int startIndex, int endIndex) {
    
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

int main() {

    char s[] = "ABCDE";
    reverseSubstring(s, 1, 4);

    puts(s);

    return 0;
}