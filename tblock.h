#include "block.h"

class TBlock : public Block {
    string name;
    public:
    void clockWise() override;
    void counterClockWise() override;
    TBlock();
}