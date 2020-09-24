/**
 * Author: Miguel Tomé
 * Purpose: The challenge is to develop a program that checks if a line segment 
 *  intersects a rectagle
 *  Print T or F if intersects of not
 *  This version will use struct to represent Point, Rectangle, Line, etc.
 * Date: 24-09-2020
 */

#include <stdio.h>
#include <stdbool.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point p1, p2;
} Line;

typedef struct {
    Point leftTop, rightBottom;
} Rectangle;

/**
 * Checks the intersection between two lines
 * return true if the lines intersects
 */
bool intersectLineLine(Line l1, Line l2) {

    float q = (l1.p1.y - l2.p1.y) * (l2.p2.x - l2.p1.x) - (l1.p1.x - l2.p1.x) * (l2.p2.y - l2.p1.y);
    float d = (l1.p2.x - l1.p1.x) * (l2.p2.y - l2.p1.y) - (l1.p2.y - l1.p1.y) * (l2.p2.x - l2.p1.x);

    if (d == 0) {
        return false;
    }

    float r = q / d;

    q = (l1.p1.y - l2.p1.y) * (l1.p2.x - l1.p1.x) - (l1.p1.x - l2.p1.x) * (l1.p2.y - l1.p1.y);
    float s = q / d;

    if (r < 0 || r > 1 || s < 0 || s > 1) {
        return false;
    }

    return true;
}

/**
 * Checks if a given point is insede a given rectangle
 * rectangle left, right, bottom and top stablish an order
 * return true if the point is inside the or false otherwise
 */
bool contains(Rectangle r, Point p) {
    
    if (p.x < r.leftTop.x || p.x > r.rightBottom.x || p.y < r.rightBottom.y || p.y > r.leftTop.y) {
        return false;
    }

    return true;
}

/**
 * Checks the intersection of a line segment and a rectangle
 * return true if intersects and false otherwise
 * 
 * Aproach
 * Check if one of the points of the line is insede the rectangle
 *  or if at least one of the edges of the rectangle intersects the line
 */
bool intersectRectangleLine(Rectangle r, Line l) {
    
    /* the four lines that represents the rectangle */
    Line rectangleTop, rectangleLeft, rectangleBottom, rectangleRight;

    /* point left-top */
    rectangleTop.p1 = rectangleLeft.p1 = r.leftTop;

    /* point right-top */
    rectangleTop.p2.x = rectangleRight.p2.x = r.rightBottom.x;
    rectangleTop.p2.y = rectangleRight.p2.y = r.leftTop.y;

    /* point left-bottom */
    rectangleLeft.p2.x = rectangleBottom.p1.x = r.leftTop.x;
    rectangleLeft.p2.y = rectangleBottom.p1.y = r.rightBottom.y;

    /* point right-bottom */
    rectangleBottom.p2 = rectangleRight.p1 = r.rightBottom;

    if ( contains(r, l.p1) /* line start point */
        || contains(r, l.p2) /* line end point */
        || intersectLineLine(l, rectangleTop) /* rectangle top edge */
        || intersectLineLine(l, rectangleLeft) /* rectangle left edge */ 
        || intersectLineLine(l, rectangleBottom) /* rectangle bottom edge */ 
        || intersectLineLine(l, rectangleRight) ) /* rectangle right edge */ 
    {
        return true;
    }

    return false;
}

/**
 * Convert from the coordenates of two points into a rectangle
 * left, right, bottom and top doens't stablish an order, but they must at
 *  the Rectangle representation
 * return a rectangle representation
 */
Rectangle convertToRectangle(int xleft, int ytop, int xright, int ybottom) {

    /* left, right, bottom and top doesn't stablish an order  */
    Rectangle r;
    r.leftTop.x = MIN(xleft, xright);
    r.leftTop.y = MAX(ybottom, ytop);
    r.rightBottom.x = MAX(xleft, xright);
    r.rightBottom.y = MIN(ybottom, ytop);
    
    return r;
}

/**
 * Convert from the coordenates of two points into a Line
 * return a Line representation
 */
Line convertToLine(int xstart, int ystart, int xend, int yend) {

    Line l;
    l.p1.x = xstart;
    l.p1.y = ystart;
    l.p2.x = xend;
    l.p2.y = yend;

    return l;
}

int main() {

    int n; /* the number of test cases */
    scanf("%d", &n);

    int i;
    for (i = 0; i < n; i++) {

        int xstart, ystart, xend, yend; /* coordenates of the line segment */
        int xleft, ytop, xright, ybottom; /* coordenates of the rectangle */

        scanf("%d %d %d %d", &xstart, &ystart, &xend, &yend);
        scanf("%d %d %d %d\n", &xleft, &ytop, &xright, &ybottom);

        Rectangle r = convertToRectangle(xleft, ytop, xright, ybottom);
        Line l = convertToLine(xstart, ystart, xend, yend);

        if (intersectRectangleLine(r, l)) {
            puts("T");
        }
        else {
            puts("F");
        }
    }    

    return 0;
}
