#include "block.h"

class CentreBlock : public Block {
    string name;
    public:
    void clockWise() override;
    void counterClockWise() override;
    CentreBlock();
}