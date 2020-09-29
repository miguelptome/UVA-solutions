package pt.courses.uva.p297;

public class EmptyQuadrant implements Node {
    
    @Override
    public boolean isLeaf() {
	return true;
    }

    @Override
    public String toString() {
	return "E";
    }

}
