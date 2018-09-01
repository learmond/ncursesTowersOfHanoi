#ifndef DISK_H_
#define DISK_H_

#include <string>
#include "shape.h"

class Disk : public Shape
{
public:

    Disk( int size, int x1, int x2, int x3, int y );

    virtual void draw();

    void erase();

    inline int getSize()
    {
        return _s.length();
    }

    void moveUp();

    void moveLeft();

    void moveRight();

private:

    int _x1, _x2, _x3, _moveY;
    std::string     _s, _sClr;
};

#endif //DISK_H_
