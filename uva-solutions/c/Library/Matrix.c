/**
 * Author: Miguel Tomé
 * Purpose: This file have the purpose of having some common and useful functions
 *  that are not available on standard lybrary of c.
 * Date: 01-10-2020
 */

#include <stdio.h>

/**
 * This function will rotate a square of chars 90 degres clockwise.
 * 
 *      Example:
 *      #define SIZE 2

        char square[SIZE][SIZE] = {
            {'A', 'B'},
            {'C', 'D'}
        };

        rotateSquareClockwise90(SIZE, square);
 * 
 * @param size is the square dimensions
 * @param square to rotate
 * @return void
 */
void rotateSquareClockwise90(int size, char square[size][size]) {
    
    /**
     * A possible aproach, to do not use any more memory is to see the cyrcles 
     * of the square. Use a temporary variable to rotate the elements of the cyrcle.
     */

    /* monitoring the circle */
    int i;
    for (i = 0; i < (size / 2); i++) {

        /* iterate over the current cyrcle */
        int j;
        for (j = i; j < (size - i - 1); i++) {

            /**
             * make the swop
             * rotate over 4 elements
             */

            /* save left values temporarly */
            int aux = square[size - 1 - j][i];

            /* move values from bottom to left */
            square[size - 1 - j][i] = square[size - 1 - i][size - 1 - j];

            /* move values from right to bottom */
            square[size - 1 - i][size - 1 - j] = square[j][size - 1 - i];

            /* move values from top to right */
            square[j][size - 1 - i] = square[i][j];

            /* assign temp to top */
            square[i][j] = aux;
        }
    }
}

/**
 * This function will rotate a square of chars 90 degres clockwise.
 * Not so efficient approach approach, by using an aux square matrix
 * but better for reading purposes.
 * 
 *      Example:
        #define SIZE 2

        char square[SIZE][SIZE] = {
            {'A', 'B'},
            {'C', 'D'}
        };

        rotateSquareClockwise90_v2(SIZE, square);
 *
 * @param size is the square dimensions
 * @param square to rotate
 * @return void
 */
void rotateSquareClockwise90_v2(int size, char square[size][size]) {
    
    char aux[size][size]; /* the aux square used to copy and rotate */

    /**
     * Rotate and copy from square to aux
     */
    int i;
    for (i = 0; i < size; i++) {

        int j;
        for (j = 0; j < size; j++) {

            aux[j][size - i - 1] = square[i][j];
        }
    }

    /**
     * copy back from aux to square
     */
    
    for (i = 0; i < size; i++) {

        int j;
        for (j = 0; j < size; j++) {

            square[i][j] = aux[i][j];
        }
    }
}

int main() {

    return 0;
}