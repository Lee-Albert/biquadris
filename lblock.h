#include "block.h"

class LBlock : public Block {
    string name;
    public:
    void clockWise() override;
    void counterClockWise() override;
    LBlock();
}