/**
 * Author: Miguel Tomé
 * Purpose: Implement a 2nd version of UVA challenge 621, but this time assume
 *  that the secret has no more that 2000 chars.
 * Date: 28-09-2020
 */

#include <stdio.h>
#include <string.h>

#define SECRET_MAX_LEN 2000

/**
 * This function will receive a secret and decrypt the result, as if it is 
 *  positive, negative as if the experiment failed or was not completed
 * return +, -, * or ? for each of the cases above
 */
char *decrypt(char *secret) {

    int secretLength = strlen(secret);

    if (strcmp(secret, "1") == 0 || strcmp(secret, "4") == 0 || strcmp(secret, "78") == 0) {
        return "+";
    }
    if (secretLength >= 2 && secret[secretLength - 2] == '3' && secret[secretLength - 1] == '5') {
        return "-";
    }
    if (secretLength >= 2 && secret[0] == '9' && secret[secretLength - 1] == '4') {
        return "*";
    }
    return "?";
}

int main() {

    char secret[SECRET_MAX_LEN]; /* the secret to decrypt */

    int n; /* number of secrets to evaluate */
    scanf("%d\n", &n);

    while (n--) {

        scanf("%s", &secret);

        char *result = decrypt(secret);
        puts(result);
    }

    return 0;
}