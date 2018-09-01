
#include "tower.h"
#include "disk.h"

Tower::Tower(int x, int y, int height)
: Shape(x,y), _height(height)
{
}

void Tower::addDisk(Disk* d)
{
    _t.push_back(d);
}

void Tower::draw()
{
    drawTower();
    drawDisks();
}

void Tower::drawDisks()
{
    int i = 0;
    for( Disk* d : _t )
    {
        d->drawAt(_x, _y - (i++ * 2));
    }
}

void Tower::drawTower()
{
    int h = _height;
    while( h-- )
    {
        mvaddch(_y - h, _x, '|');
    }
}

Disk* Tower::rmDisk()
{
    Disk* d = nullptr;
    if( !_t.empty() )
    {
        d = _t.back();
        _t.pop_back();
    }
    return d;
}

Disk* Tower::tryDisk(Disk* d)
{
    if( _t.empty() || (_t.size() && d->getSize() < _t.back()->getSize()) )
    {
        d->erase();
        addDisk(d);
        return nullptr;
    }
    beep();
    flash();
    return d;
}
