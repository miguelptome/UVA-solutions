package pt.courses.uva.p297;

public class FilledQuadrant extends WeightedNode implements Node {

    public FilledQuadrant(int weight) {
	super(weight);
    }
    
    @Override
    public boolean isLeaf() {
	return true;
    }

    @Override
    public String toString() {
	return "F"+getWeight();
    }
    
}
