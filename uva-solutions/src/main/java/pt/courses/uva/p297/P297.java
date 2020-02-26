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
//	    Node quadtree2 = createQuadtree(preOrder2, new int[] { 0 }, 0);
	    Node quadtree2 = mergeQuadtree(quadtree1, preOrder2, new int[] { 0 }, 0);
	    
//	    dfsQuadtree(quadtree1, out);
	    dfsQuadtree(quadtree2, out);
	    
//	    out.println("There are " + numOfFilledPixels(quadtree1) + " black pixels.");
	    out.println("There are " + numOfFilledPixels(quadtree2) + " black pixels.");
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
    
    
    
    // FIX 
    // this implementation does not work because when a node is filled on the tree
    // the pre string is is not processed and we loose the sync bettwen the both.
    private static Node mergeQuadtree(Node quadtree1, char[] preOrder2, int[] currLetterIndex, 
	    	int nodeDepth) {
	
	if (quadtree1 instanceof FilledQuadrant)
	    return quadtree1;
	if (quadtree1 instanceof EmptyQuadrant)
	    return createQuadtree(preOrder2, currLetterIndex, nodeDepth);
	
	switch (preOrder2[currLetterIndex[0]++]) {
	case 'p':
	    
	    Quadtree quadtree = new Quadtree();
	    for (Node quadrant: ((Quadtree)quadtree1).getQuadrants()) {
		quadtree.addQuadrant(mergeQuadtree(quadrant, preOrder2, currLetterIndex, nodeDepth+1));
	    }
	    
//	    // --
//	    Iterator<Node> it = ((Quadtree)quadtree1).getQuadrants().iterator();
//	    
//	    while (it.hasNext()) {
//		Node quadrant = it.next();
//		quadrant = mergeQuadtree(quadrant, preOrder2, currLetterIndex, nodeDepth+1);
//	    }
	    
//	    for (Node quadrant: ((Quadtree)quadtree1).getQuadrants()) {
//		quadrant = mergeQuadtree(quadrant, preOrder2, currLetterIndex, nodeDepth+1);
//	    }
    	    return quadtree;
    	case 'f':
    	    return new FilledQuadrant(numOfPixelsAt(nodeDepth));
    	case 'e':
    	    return quadtree1;
	}	
	return null;
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
