#include "block.h"

class ZBlock : public Block {
    string name;
    public:
    void clockWise() override;
    void counterClockWise() override;
    ZBlock();
}