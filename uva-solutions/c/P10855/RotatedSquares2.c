/**
 * Author: Miguel Tomé
 * Purpose: Improve the version one implementation, by rewriting the rotation 
 *  and use and aux matrix this time. Also write a check function that verify the 
 *  match between the small square and the current segment of the larger square
 *  to reduce the complexity of countAppearances function.
 * Date: 01-10-2020
 */

#include <stdio.h>
#include <stdbool.h>

/**
 * This function will rotate a square of chars 90 degres clockwise.
 * New approach, by using an aux square matrix
 * 
 * @Param size is the square dimensions
 * @Param square to rotate
 * @Return void
 */
void rotateSquare90Clockwise(int size, char square[size][size]) {
    
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

/**
 * This function verify the appearance between a fragment of the large square
 *  and the small square.
 * 
 * @Param i1, j1 are the start checking position at the large square
 * @Param largeSize, smallSize are the dimentions of large and small squares
 * @Param largeSquare, smallSqauare are que squares
 * @Return true if the fragment of the large square and the small square matched
 *  or false otherwise
 */
bool matchAppearance(int i1, int j1, int largeSize, char largeSquare[largeSize][largeSize],
                int smallSize, char smallSquare[smallSize][smallSize]) {

    /**
     * For each position of the monitor, compare the small square
     *  with the larger square
     * Monitoring on the small square
     */

    int i;
    for (i = 0; i < smallSize; i++) {

        int j;
        for (j = 0; j < smallSize; j++) {

            if (largeSquare[i1 + i][j1 + j] != smallSquare[i][j]) {

                return false;
            }
        }
    }

    /**
     * If the fragment of the large square and the square are equals 
     */
    return true;
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
             * If the current fragment of the larger square is equal
             * to the small square 
             */
            if (matchAppearance(i, j, largeSize, largeSquare, smallSize, smallSquare)) {
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