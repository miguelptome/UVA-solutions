/**
 * Author: Miguel Tomé
 * Purpose: This file have the purpose of having some common and useful functions
 *  that are not available on standard lybrary of c.
 * Date: 01-10-2020
 */

#include <stdio.h>
#include <stdbool.h>

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
 * This function checks if two lines intersect themselfs
 * 
 *      @example
        Line l1;
        l1.p1.x = 1; l1.p1.y = 1; 
        l1.p2.x = 3; l1.p2.y = 3;

        Line l2;
        l2.p1.x = 1; l2.p1.y = 3;
        l2.p2.x = 3; l2.p2.y = 1;

        bool result = intersectLineLine(l1, l2);
 * 
 * @param l1 is the 1st line
 * @param l2 is the 2nd line
 * @return true if the lines intersect
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
 * Checks if a given point is inside a given rectangle
 * Rectangle left, right, bottom and top stablish an order
 * 
 *      @example
        Point p1;
        p1.x = 1; p1.y = 3;

        Point p2;
        p2.x = 3; p2.y = 1;

        Rectangle r;
        r.leftTop = p1;
        r.rightBottom = p2;

        Point p3;
        p3.x = 2; p3.y = 2;

        bool result = containsRectanglePoint(r, p3);
 * 
 * @param r is the rectangle
 * @param p is the point
 * @return true if the point is inside the or false otherwise
 */
bool containsRectanglePoint(Rectangle r, Point p) {
    
    if (p.x < r.leftTop.x || p.x > r.rightBottom.x || p.y < r.rightBottom.y || p.y > r.leftTop.y) {
        return false;
    }

    return true;
}

/**
 * This function checks if a line segment and a rectangle intersect. Depend of 
 * functions @containsRectanglePoint and @intersectLineLine
 * 
 *      @example
        Point p1, p2;
        p1.x = 1; p1.y = 3;
        p2.x = 3; p2.y = 1;

        Rectangle r;
        r.leftTop = p1; r.rightBottom = p2;

        Point p3, p4;
        p3.x = 2; p3.y = 2;
        p4.x = 10; p4.y = 10;

        Line l;
        l.p1 = p3; l.p2 = p4;

        bool result = intersectRectangleLine(r, l);
 * 
 * @param r is the rectangle
 * @param l is the line segment
 * @return true if intersects and false otherwise
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

    if ( containsRectanglePoint(r, l.p1) /* line start point */
        || containsRectanglePoint(r, l.p2) /* line end point */
        || intersectLineLine(l, rectangleTop) /* rectangle top edge */
        || intersectLineLine(l, rectangleLeft) /* rectangle left edge */ 
        || intersectLineLine(l, rectangleBottom) /* rectangle bottom edge */ 
        || intersectLineLine(l, rectangleRight) ) /* rectangle right edge */ 
    {
        return true;
    }

    return false;
}

int main() {

    Point p1, p2;
    p1.x = 1; p1.y = 3;
    p2.x = 3; p2.y = 1;

    Rectangle r;
    r.leftTop = p1; r.rightBottom = p2;

    Point p3, p4;
    p3.x = 2; p3.y = 2;
    p4.x = 10; p4.y = 10;

    Line l;
    l.p1 = p3; l.p2 = p4;

    bool result = intersectRectangleLine(r, l);

    printf("%d\n", result);

    return 0;
}