#ifndef BLOCKPRINT_H
#define BLOCKPRINT_H
#include <vector>
#include <string>

struct BlockPrint {
    vector<string> IBlock { "IIII", "    "};
    vector<string> JBlock { "J  ", "JJJ"};
    vector<string> LBlock { "  L", "LLL"};
    vector<string> OBlock { "OO", "OO"};
    vector<string> SBlock { " SS", "SS "};
    vector<string> ZBlock { "ZZ ", " ZZ"};
    vector<string> TBlock { " T ", "TTT"};
};

#endif 

