/**
 * Author: Miguel Tomé
 * Purpose: The challenge is to develop a program that checks if a line segment 
 *  intersects a rectagle
 *  Print T or F if intersects of not
 * Date: 24-09-2020
 */

#include <stdio.h>
#include <stdbool.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

bool lineIntersectsLine(int xl1p1, int yl1p1, int xl1p2, int yl1p2, /* line 1 coordenates */
                    int xl2p1, int yl2p1, int xl2p2, int yl2p2) /* line 2 coordetates */
{

    float q = (yl1p1 - yl2p1) * (xl2p2 - xl2p1) - (xl1p1 - xl2p1) * (yl2p2 - yl2p1);
    float d = (xl1p2 - xl1p1) * (yl2p2 - yl2p1) - (yl1p2 - yl1p1) * (xl2p2 - xl2p1);

    if (d == 0) {
        return false;
    }

    float r = q / d;

    q = (yl1p1 - yl2p1) * (xl1p2 - xl1p1) - (xl1p1 - xl2p1) * (yl1p2 - yl1p1);
    float s = q / d;

    if (r < 0 || r > 1 || s < 0 || s > 1) {
        return false;
    }

    return true;
}

/**
 * Checks if a given point is insede a given rectangle 
 * returns true the point is inside the or false otherwise
 */
bool rectangleContainsPoint(int xleft, int ytop, int xright, int ybottom, /* rectangle coordetates */
                    int x, int y) /* point coordetates */
{
    /* left, right, bottom and top doesn't stablish an order  */
    int _xleft = MIN(xleft, xright);
    int _xright = MAX(xleft, xright);
    int _ybottom = MIN(ybottom, ytop);
    int _ytop = MAX(ybottom, ytop);

    if (x < _xleft || x > _xright || y < _ybottom || y > _ytop) {
        return false;
    }

    return true;
}

/**
 * Checks the intersection of a line segment and a rectangle
 * return true if intersects and false otherwise
 * 
 * Aproach A
 * One possible aproach is to check if the line is completely insede the rectangle
 *  or if at least one of the edges of the rectangle intersects the line
 */
bool lineIntersectRectangle(int xstart, int ystart, int xend, int yend, /* line coordenates */
                    int xleft, int ytop, int xright, int ybottom) /* rectangle coordetates */
{

    if ( rectangleContainsPoint(xleft, ytop, xright, ybottom, xstart, ystart) /* line start point */
        || rectangleContainsPoint(xleft, ytop, xright, ybottom, xend, yend) /* line end point */
        || lineIntersectsLine(xstart, ystart, xend, yend, xleft, ytop, xright, ytop)  /* rectangle top edge */ 
        || lineIntersectsLine(xstart, ystart, xend, yend, xleft, ytop, xleft, ybottom)  /* rectangle left edge */ 
        || lineIntersectsLine(xstart, ystart, xend, yend, xleft, ybottom, xright, ybottom)  /* rectangle bottom edge */ 
        || lineIntersectsLine(xstart, ystart, xend, yend, xright, ybottom, xright, ytop) ) /* rectangle right edge */ 
    {
        return true;
    }

    return false;
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

        if (lineIntersectRectangle(xstart, ystart, xend, yend, xleft, ytop, xright, ybottom)) {
            puts("T");
        }
        else {
            puts("F");
        }
    }    

    return 0;
}
