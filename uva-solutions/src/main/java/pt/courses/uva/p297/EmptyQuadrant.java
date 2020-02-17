package pt.courses.uva.p297;

public class EmptyQuadrant implements Node {

    @Override
    public String toString() {
	return "E";
    }
    
    @Override
    public boolean isLeaf() {
	return true;
    }

}
