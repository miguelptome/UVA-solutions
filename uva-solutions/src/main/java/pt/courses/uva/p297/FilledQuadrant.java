package pt.courses.uva.p297;

public class FilledQuadrant implements Node {

    @Override
    public String toString() {
	return "F";
    }
    
    @Override
    public boolean isLeaf() {
	return true;
    }

}
