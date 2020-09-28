/**
 * Author: Miguel Tomé
 * Purpose: Develop a program to solve the UVA 621 challenge
 * Date: 25-09-2020
 */

#include <stdio.h>

/**
 * This method will process the secret from the terminal
 * The secret head and tail will been stored at secretHead and secretTail
 * return the secret length
 */
int scanSecret(char *secretHead, char *secretTail) {

    int length = 0;

    char c; /* the char that will be readed from the terminal */
    while (scanf("%c", &c) && c != '\n') {

        /* update the head of the secret */
        if (length < 3) {
            secretHead[length] = c;
        }

        /* update the tail of the secret */
        secretTail[0] = secretTail[1];
        secretTail[1] = c;

        length++;
    }

    return length;
}

/**
 * This method will analize a given secret head and tail 
 * return +, -, * or ? depending of some rules
 */
char analyseSecret(char *secretHead, char *secretTail, int length) {
    switch (length) {
        case 1:
            if (secretHead[0] == '1' || secretHead[0] == '4') {
                return '+';
            }
            break;
        case 2: 
            if (secretHead[0] == '7' || secretHead[1] == '8') {
                return '+';
            }
            break;
        default: /* length > 2 */
            if (secretTail[0] == '3' && secretTail[1] == '5') {
                return '-';
            }
            if (secretHead[0] == '9' && secretTail[1] == '4') {
                return '*';
            }

            if (secretHead[0] == '1' && secretHead[1] == '9' && secretHead[2] == '0') {
                return '?';
            }
            break;
    }
}

int main() {

    int n; /* the number of lines to decrypt */
    scanf("%d\n", &n);

    int i;
    for (i = 0; i < n; i++) {
      
        char secretHead[3]; /* the first 3 digits of the head */
        char secretTail[2]; /* the last 2 digits of the tail */

        int length = scanSecret(secretHead, secretTail); /* read from terminal */

        char result = analyseSecret(secretHead, secretTail, length);
        printf("%c\n", result);
    }

    return 0;
}