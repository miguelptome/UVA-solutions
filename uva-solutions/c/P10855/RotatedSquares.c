/**
 * Author: Miguel Tomé
 * Purpose: Write a program that count the apearence of a given small square in
 *  a biggest square. Analize all the 4 possible rotations of the square.
 * Date: 30-09-2020
 */

#include <stdio.h>
#include <stdbool.h>

/**
 * This function will rotate a square of chars 90 degres clockwise.
 * 
 * @Param size is the square dimensions
 * @Param square to rotate
 * @Return void
 */
void rotateSquare90Clockwise(int size, char square[size][size]) {
    
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
 * This function counts the number of appearances of the small square into the 
 *  large square.
 * 
 * @Param largeSize, smallSize are the dimentions of large and small squares
 * @Param largeSquare, smallSqauare are que squares
 * @Return the number of appearances of smallSquare into the largeSquare
 */
int countAppearances(int largeSize, char largeSquare[largeSize][largeSize],
                int smallSize, char smallSquare[smallSize][smallSize]) {

    int total = 0; /* the number of appearances */

    /**
     * The strategy is to create a monitor that goes from the top left corner of 
     *  the larger quare to the point where the monitor delimilers the small square
     *  inside the larger square
     * Monitoring on the larger square
     */

    int i;
    for (i = 0; i <= (largeSize - smallSize); i++) {

        int j;
        for (j = 0; j <= (largeSize - smallSize); j++) {

            /** 
             * Flag the match between the small square and the 
             * current fragment on the larger square
             */
            bool flag = true; 

            /**
             * For each position of the monitor, compare the small square
             *  with the larger square
             * Monitoring on the small square
             */

            int k;
            for (k = 0; k < smallSize && flag; k++) {

                int l;
                for (l = 0; l < smallSize; l++) {

                    if (largeSquare[i + k][j + l] != smallSquare[k][l]) {

                        flag = false;
                        break;
                    }
                }
            }

            /**
             * If the current fragment of the larger square is equal
             * to the small square 
             */
            if (flag) {
                total++; 
            }
        }
    }
    
    return total;
}

/**
 * This functions will count the appearances of the small square on the large square
 *  and store the result into appearances array. 
 * 
 * @Param appearances at each rotation (0, 90, 180, 270)
 * @Param largeSize, smallSize are the dimentions of large and small squares
 * @Param largeSquare, smallSqauare are que squares
 * @Return void
 */
void countAppearancesForAllRotations(int *appearances, int largeSize, char largeSquare[largeSize][largeSize],
                int smallSize, char smallSquare[smallSize][smallSize]) {
    
    appearances[0] = countAppearances(largeSize, largeSquare, smallSize, smallSquare);

    int i;
    for (i = 1; i < 4; i++) {
        rotateSquare90Clockwise(smallSize, smallSquare);
        appearances[i] = countAppearances(largeSize, largeSquare, smallSize, smallSquare);
    }
}

/**
 * This function reads a square of chars, each row separated by \n from terminal.
 * 
 * @Param size of the square
 * @Param square 
 * @Return void
 */
void readSquareFromTerminal(int size, char square[size][size]) {

    int i;
    for (i = 0; i < size; i++) {
        
        int j;
        for (j = 0; j < size; j++) {

            square[i][j] = getchar();
        }

        getchar(); /* read the \n from the end of each row  */
    }
}

int main() {

    int largeSize, smallSize; /* the size of the squares */

    while (scanf("%d %d\n", &largeSize, &smallSize) && largeSize) { /* read until 0 0 */

        char largeSquare[largeSize][largeSize];
        readSquareFromTerminal(largeSize, largeSquare);

        char smallSquare[smallSize][smallSize];
        readSquareFromTerminal(smallSize, smallSquare);

        /**
         * Count the appearances on the 4 possible rotations of the small square
         * total appearances at each rotation (0, 90, 180, 270)
         */
        int appearances[4];
        countAppearancesForAllRotations(appearances, largeSize, largeSquare, smallSize, smallSquare);

        printf("%d %d %d %d\n", appearances[0], appearances[1], appearances[2], appearances[3]);
    }

    return 0;
}