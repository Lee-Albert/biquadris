#include "block.h"

class OBlock : public Block {
    string name;
    public:
    void clockWise() override;
    void counterClockWise() override;
    OBlock();
}