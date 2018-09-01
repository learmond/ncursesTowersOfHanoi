
#include <unistd.h>
#include <iostream>
#include <stack>
#include <ncurses.h>
#include "disk.h"
#include "selector.h"
#include "tower.h"

using namespace std;

int x1 = 15, x2 = 40, x3 = 65;
int towerHeight = 6, towerY = 10, yDiskMove = 3;

int main(int argc, char* argv[])
{
    initscr();			/* Start curses mode */
    clear();
    noecho();
    cbreak();
    curs_set(0);
    keypad(stdscr, TRUE);

    printw("Towers Of Hanoi");
    mvprintw(14, 0, "Move Count: 0" );
    mvprintw(15, 0, "'q' to quit");

    Disk d1(5, x1, x2, x3, 3),
         d2(11,x1, x2, x3, 3),
         d3(17, x1, x2, x3, 3);
    
    Tower t1(x1, towerY, towerHeight);
    Tower t2(x2, towerY, towerHeight);
    Tower t3(x3, towerY, towerHeight);

    t1.addDisk(&d3);
    t1.addDisk(&d2);
    t1.addDisk(&d1);

    t1.draw();
    t2.draw();
    t3.draw();
    
    Selector sel(3, x1, x2, x3, 12);
    refresh();
    
    int ci;
    int moveCount = 0;
    bool win = false;

    Disk* moveDisk = nullptr;
    while(!win && (ci = getch()) != 'q' )
    {
        if( ci == KEY_LEFT )
        {
            sel.moveLeft();
            if( moveDisk ) 
            {
                moveDisk->moveLeft();
            }
        }
        else if( ci == KEY_RIGHT )
        {
            sel.moveRight();
            if( moveDisk ) 
            {
                moveDisk->moveRight();
            }
        }
        else if( ci == KEY_UP && !moveDisk )
        {
            if( sel.at() == x1 && t1.hasDisk() )
            {
                moveDisk = t1.rmDisk();
                moveDisk->moveUp();
            }
            else if( sel.at() == x2 && t2.hasDisk() )
            {
                moveDisk = t2.rmDisk();
                moveDisk->moveUp();
            }
            else if( sel.at() == x3 && t3.hasDisk() )
            {
                moveDisk = t3.rmDisk();
                moveDisk->moveUp();
            }
        }
        else if( ci == KEY_DOWN && moveDisk )
        {
            if( sel.at() == x1 )
            {
                moveDisk = t1.tryDisk(moveDisk);
                ++moveCount;
            }
            else if( sel.at() == x2 )
            {
                moveDisk = t2.tryDisk(moveDisk);
                ++moveCount;
            }
            else if( sel.at() == x3 )
            {
                moveDisk = t3.tryDisk(moveDisk);
                ++moveCount;
            }
        }

        t1.draw();
        t2.draw();
        t3.draw();

        move(14, 12);
        clrtoeol();
        mvprintw(14, 12, std::to_string(moveCount).c_str());
        refresh();

        if( t2.disks().size() == 3 || t3.disks().size() == 3 )
        {
            flash();
            sleep(1);
            flash();
            mvprintw(14, 24, "Winner Winner Chicken Dinner");
            win = true;
        }
        
        refresh();
    }

    getch();
	endwin();			/* End curses mode		  */

	return 0;
}
