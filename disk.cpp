
#include "disk.h"

using namespace std;

Disk::Disk( int size, int x1, int x2, int x3, int y )
: _x1(x1), _x2(x2), _x3(x3), _moveY(y), _s(size, '='), _sClr(size, ' ')
{

}

void Disk::draw()
{
    mvprintw(_y, _x - _s.size()/2, _s.c_str());
}

void Disk::erase()
{
    mvprintw(_y, _x - _s.size()/2, _sClr.c_str());
}

void Disk::moveLeft()
{
    erase();
    drawAt( std::max(_x - (_x2 - _x1), _x1), _moveY );
}

void Disk::moveRight()
{
    erase();
    drawAt( std::min(_x + (_x2 - _x1), _x3), _moveY );
}

void Disk::moveUp()
{
    erase();
    drawAt(_x, _moveY);
}

