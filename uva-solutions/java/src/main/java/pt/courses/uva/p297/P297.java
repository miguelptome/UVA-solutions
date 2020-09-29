package pt.courses.uva.p297;

import java.io.PrintWriter;
import java.util.Iterator;
import java.util.Scanner;

public class P297 {
    
    public static void main(String args[]) {
	Scanner scn = new Scanner(System.in);
	PrintWriter out = new PrintWriter(System.out);
		
	int nCases = scn.nextInt();
	for (int i=0; i<nCases; i++) {
	    
	    char[] preOrder1 = scn.next().toCharArray();
	    char[] preOrder2 = scn.next().toCharArray();
	    
	    Node quadtree1 = createQuadtree(preOrder1, new int[] { 0 }, 0);
	    Node quadtree2 = createQuadtree(preOrder2, new int[] { 0 }, 0);
	    Node mergedQuadtree = mergeQuadtree(quadtree1, quadtree2);
	    
//	    dfsQuadtree(quadtree1, out);
//	    dfsQuadtree(quadtree2, out);
//	    dfsQuadtree(mergedQuadtree, out);
	    
//	    out.println("There are " + numOfFilledPixels(quadtree1) + " black pixels.");
//	    out.println("There are " + numOfFilledPixels(quadtree2) + " black pixels.");
	    out.println("There are " + numOfFilledPixels(mergedQuadtree) + " black pixels.");
	}
		
	out.flush();
	out.close();
	scn.close();
    }
    
    private static int numOfFilledPixels(Node quadtree) {
	if (quadtree.isLeaf()) {
	    try {
        	return ((FilledQuadrant)quadtree).getWeight();
	    }
	    catch (ClassCastException e) {
	    }
	    return 0;
	}
	
	int total = 0;
	for (Node quadrant: ((Quadtree)quadtree).getQuadrants()) {
	    total += numOfFilledPixels(quadrant);
	}
	return total;
    }
    
    // TODO
    // merge two trees
    // an alternative is to process the two trees first and then merge the both
    // when one of the both are filled, keep filled
    // when one of the both are empty, keep the other
    // otherwise create a new quadtree with the result of the sub merge
    
    private static Node mergeQuadtree(Node quadtree1, Node quadtree2) {
	
	// when one of the both are filled, keep filled
	if (quadtree1 instanceof FilledQuadrant)
	    return quadtree1;
	if (quadtree2 instanceof FilledQuadrant)
	    return quadtree2;
	
	// when one of the booth are empty, return the other
	if (quadtree1 instanceof EmptyQuadrant)
	    return quadtree2;
	if (quadtree2 instanceof EmptyQuadrant)
	    return quadtree1;
	
	// otherwise create a new quadtree with the result of the sub merge 
	Iterator<Node> itQuadtree1 = ((Quadtree)quadtree1).getQuadrants().iterator();
	Iterator<Node> itQuadtree2 = ((Quadtree)quadtree2).getQuadrants().iterator();
	
	Quadtree quadrant = new Quadtree();
	while (itQuadtree1.hasNext()) {
	    quadrant.addQuadrant(mergeQuadtree(itQuadtree1.next(), itQuadtree2.next()));
	}
	
	return quadrant;
    }
    
    private static Node createQuadtree(char[] preOrder, int[] currLetterIndex, int nodeDepth) {
	
	switch (preOrder[currLetterIndex[0]++]) {
	case 'p':
    	    Quadtree quadtree = new Quadtree();
    	    quadtree.addQuadrant(createQuadtree(preOrder, currLetterIndex, nodeDepth+1));
    	    quadtree.addQuadrant(createQuadtree(preOrder, currLetterIndex, nodeDepth+1));
    	    quadtree.addQuadrant(createQuadtree(preOrder, currLetterIndex, nodeDepth+1));
    	    quadtree.addQuadrant(createQuadtree(preOrder, currLetterIndex, nodeDepth+1));
    	    return quadtree;
    	case 'f':
    	    return new FilledQuadrant(numOfPixelsAt(nodeDepth));
    	case 'e':
    	    return new EmptyQuadrant();
	}	
	return null;
    }
    
    private static int numOfPixelsAt(int nodeDepth) {
	return (new int[] { 1024, 256, 64, 16, 4, 1 })[nodeDepth];
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
