#include "block.h"

class JBlock : public Block {
    string name;
    public:
    void clockWise() override;
    void counterClockWise() override;
    JBlock();
}