/**
 * Author: Miguel Tomé
 * Purpose: This file have the purpose of having some common and useful functions
 *  that are not available on standard lybrary of c.
 * Date: 01-10-2020
 */

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point p1, p2;
} Line;

typedef struct {
    Point leftTop, rightBottom;
} Rectangle;


bool intersectLineLine(Line l1, Line l2);

bool containsRectanglePoint(Rectangle r, Point p);

bool intersectRectangleLine(Rectangle r, Line l);
