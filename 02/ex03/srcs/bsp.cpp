#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Point PointA(a.get_x(), a.get_y());
    Point PointB(b.get_x(), b.get_y());
    Point PointC(c.get_x(), c.get_y());
    Point PointP(point.get_x(), point.get_y());

    Fixed cross1 = (PointC.get_x() - PointP.get_x()) * (PointA.get_y() - PointP.get_y()) - 
                   (PointC.get_y() - PointP.get_y()) * (PointA.get_x() - PointP.get_x());
    Fixed cross2 = (PointA.get_x() - PointP.get_x()) * (PointB.get_y() - PointP.get_y()) - 
                   (PointA.get_y() - PointP.get_y()) * (PointB.get_x() - PointP.get_x());
    Fixed cross3 = (PointB.get_x() - PointP.get_x()) * (PointC.get_y() - PointP.get_y()) - 
                   (PointB.get_y() - PointP.get_y()) * (PointC.get_x() - PointP.get_x());

    if ((cross1 > 0 && cross2 > 0 && cross3 > 0) || (cross1 < 0 && cross2 < 0 && cross3 < 0)) {
        return true;
    }
    return false;
}
