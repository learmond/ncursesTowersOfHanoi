
#include "selector.h"

using namespace std;

Selector::Selector( int size, int x1, int x2, int x3, int y )
: _x1(x1), _x2(x2), _x3(x3), _diff(x2 - x1), _s(size, '*')
{
    drawAt(_x1, y);
}

int Selector::at() const
{
    return _x;
}

void Selector::draw()
{
    move(_y, 0);
    clrtoeol();
    mvprintw(_y, _x - _s.size()/2, _s.c_str());
}

void Selector::moveLeft()
{
    drawAt( std::max(_x - _diff, _x1), _y );
}

void Selector::moveRight()
{
    drawAt( std::min(_x + _diff, _x3), _y );
}
