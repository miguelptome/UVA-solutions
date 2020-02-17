package pt.courses.uva.p297;

import java.util.ArrayList;
import java.util.List;

public class Quadtree implements Node {
    
    private ArrayList<Node> quadrants;
    
    public Quadtree() {
	quadrants = new ArrayList<>(4);
    }
    
    public void addQuadrant(Node quadrant) {
	quadrants.add(quadrant);
    }
    
    public List<Node> getQuadrants() {
	return quadrants;
    }
 
    @Override
    public String toString() {
	return "P";
    }

    @Override
    public boolean isLeaf() {
	return false;
    }
    
}
