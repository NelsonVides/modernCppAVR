/*
 * main, to test compilation.
 */

#include <stl/type_traits.h>
#include <stl/utility.h>
#include <avr/io.h>


class Point {
public:
    Point() : x(0), y(0) {};
    Point(int a, int b) : x(a), y(b) {};
private:
    int x;
    int y;
};

int main(void)
{
    Point a;
    Point b;
    Point c = static_cast<Point>(b);
    c = stl::move(a);
    while(1);
}
