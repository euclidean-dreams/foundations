#ifndef IMPRESARIO_UTILS_POINT_H
#define IMPRESARIO_UTILS_POINT_H

namespace impresarioUtils {

class Point {
public:
    double x;
    double y;
    double z;

    Point();

    Point(double x);

    Point(double x, double y);

    Point(double x, double y, double z);
};

}

#endif //IMPRESARIO_UTILS_POINT_H
