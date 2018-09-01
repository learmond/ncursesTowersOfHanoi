#ifndef TOWER_H_
#define TOWER_H_

#include <list>
#include "shape.h"

class Disk;

class Tower : public Shape
{
public:

    Tower( int x, int y, int height );

    void addDisk( Disk* d );

    inline const std::list<Disk*>& disks() const
    {
        return _t;
    }

    virtual void draw();

    void drawDisks();

    void drawTower();

    inline bool hasDisk() const
    {
        return _t.size() > 0;
    }

    Disk* rmDisk();

    Disk* tryDisk(Disk* d);

private:

    int                 _height;
    std::list<Disk*>    _t;
};

#endif // TOWER_H_
