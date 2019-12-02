#include "block.h"

class CentreBlock : public Block {
    public:
    void clockWise() override;
    void counterClockWise() override;
    CentreBlock();
};
