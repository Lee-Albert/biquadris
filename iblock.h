#include "block.h"

class IBlock : public Block {
    string name;
    public:
    void clockWise() override;
    void counterClockWise() override;
    IBlock();
}