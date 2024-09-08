#ifndef GRIGLIA_H_INCLUDED
#define GRIGLIA_H_INCLUDED

#include<string>;
#include "constants.h"
#include "ship.hpp"

class Grid{

public:
    Grid();
    Grid(const Grid &oldGrid);
    Grid& operator=(const Grid &right);
    ~Grid();

    void printPlayerGrid();
    void printOpponentGrid();
    bool setShip(int shipNum, int x, int y, bool o);
    void shot(int x, int y);



private:
   char theGrid[grid_dim][grid_dim];
   std::vector<Ship> shipVec;


};
#endif // GRIGLIA_H_INCLUDED
