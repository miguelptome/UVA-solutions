package pt.courses.uva.p297;

import java.io.PrintWriter;
import java.util.Scanner;

public class P297 {
    
    public static void main(String args[]) {
	Scanner scn = new Scanner(System.in);
	PrintWriter out = new PrintWriter(System.out);
		
	int nCases = scn.nextInt();
	for (int i=0; i<nCases; i++) {
	    
	    char[] preOrder1 = scn.next().toCharArray();
	    char[] preOrder2 = scn.next().toCharArray();
	    
	    Node quadtree1 = createQuadtree(preOrder1, new int[] { 0 });
	    Node quadtree2 = createQuadtree(preOrder2, new int[] { 0 });
	    
	    dfsQuadtree(quadtree1, out);
	    dfsQuadtree(quadtree2, out);
	}
		
	out.flush();
	out.close();
	scn.close();
    }
    
    // TODO
    // create a method to count the pixels of a given quadtree
    
    private static void mergeQuadtree(Node quadtree1, char[] preOrder2, int[] currLetterIndex) {
	// TODO 
	// this method will receive the quadtree one and with switch case the pre-order string 2
	// to each case take the action of keep the current branck or update it
	
    }
    
    private static Node createQuadtree(char[] preOrder, int[] currLetterIndex) {
	
	switch (preOrder[currLetterIndex[0]++]) {
	case 'p':
    	    Quadtree quadtree = new Quadtree();
    	    quadtree.addQuadrant(createQuadtree(preOrder, currLetterIndex));
    	    quadtree.addQuadrant(createQuadtree(preOrder, currLetterIndex));
    	    quadtree.addQuadrant(createQuadtree(preOrder, currLetterIndex));
    	    quadtree.addQuadrant(createQuadtree(preOrder, currLetterIndex));
    	    return quadtree;
    	case 'f':
    	    return new FilledQuadrant();
    	case 'e':
    	    return new EmptyQuadrant();
	}	
	return null;
    }
    
    private static void dfsQuadtree(Node quadtree, PrintWriter out) {
	
	out.println(quadtree);
	
	if (!quadtree.isLeaf()) {
	    for (Node quadrant: ((Quadtree)quadtree).getQuadrants()) {
		dfsQuadtree(quadrant, out);
	    }
	}
    }
    
}
