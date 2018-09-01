#ifndef SHAPE_H_
#define SHAPE_H_

#include <ncurses.h>

class Shape
{
public:

    Shape() {}
    Shape(int x, int y) : _x(x), _y(y) {}

    virtual void draw() = 0;

    void drawAt(int x, int y)
    {
        _x = x;
        _y = y;
        draw();
    }

protected:

    int _x, _y;
};

#endif // SHAPE_H_
