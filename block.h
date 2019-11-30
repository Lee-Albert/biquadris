#include <string>

class Block {
    int orientation;
    Grid *grid;
    Cell *xcells[4];
    int xPos;
    int yPos;
    public:
    virtual void clockWise() = 0;
    virtual void counterClockWise() = 0;
    void left();
    void right();
    void down();
    void drop();
    Block(int orientation, Grid grid, Cell cells, int xPos, int yPos);
    virtual ~Block();
}