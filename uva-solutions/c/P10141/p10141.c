/**
 * Author: Miguel Tome'
 * Proposal: The proposal is to implement a solution to the challenge at UVA 10141.
 * TODO:
 *      - divide the program into more functions to get better modulation
 *      - implement the solution
 *      - this program must be concluded before continue on course
 * Date: 2020-08-20 
 */

#include <stdio.h>  // to use input and output
#include <stdbool.h> // to use bool
#include <string.h> // to use strlen
#include <stdlib.h> // to use malloc

/**
 * This function will process n requirements and p proposals and
 * return the best suited proposal name 
 * @param n number of requirements
 * @param p number of proposals
 * @param stream source data stream
 */
const char* processRFP(int n, int p, FILE* stream) {
    
    /* PROCESS REQUIREMENTS */
    char requirement[80];
    int i;
    for (i=0; i<n; i++) {
        fgets(requirement, sizeof(requirement), stdin);
    }

    /* PROCESS PROPOSALS */
    char* propName = (char*) malloc(sizeof(char)*80);
    float propPrice;
    int propNumOfMetRequirements;
    for (i=0; i<p; i++) { // for each proposal
        
        fgets(propName, sizeof(char)*80, stdin);
        //propName[strlen(propName) - 1] = '\0'; // if i want to remove the \n at the end of the line

        /* PROCESS MET REQUIREMENTS */
        scanf("%f %d\n", &propPrice, &propNumOfMetRequirements);
        int j;
        for (j=0; j<propNumOfMetRequirements; j++) {
            fgets(requirement, sizeof(requirement), stdin);
        }
    }

    //char* name = propName;

    return propName;
}

int main() {

    int n, p; // nRequirements, nProposals
    int count = 0;
    const char* winnerProposalName;
    
    /* ********************************************************
     * ITERATE OVER EACH RFP
     ******************************************************** */

    scanf("%d %d\n", &n, &p);
    while (n != 0 || p != 0) {
        printf("RFP #%d\n", ++count);
        printf("%s\n", processRFP(n, p, stdin));
        scanf("%d %d\n", &n, &p);

        // TODO improve this line by avoid it
        if (!(n != 0 || p != 0)) {
            printf("/n");
        }
    }

    return 0;
}
