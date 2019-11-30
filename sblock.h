#include "block.h"

class SBlock : public Block {
    string name;
    public:
    void clockWise() override;
    void counterClockWise() override;
    SBlock();
}