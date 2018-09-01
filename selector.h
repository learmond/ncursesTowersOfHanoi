#ifndef SELECTOR_H_
#define SELECTOR_H_

#include <string>
#include "shape.h"

class Selector : public Shape
{
public:

    Selector( int size, int x1, int x2, int x3, int y );

    int at() const;

    virtual void draw();

    void moveLeft();

    void moveRight();

private:

    int             _x1, _x2, _x3, _diff;
    std::string     _s;
};

#endif //SELECTOR_H_
