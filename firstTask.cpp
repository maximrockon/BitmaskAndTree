#include <vector>
#include "bitmask.hpp"

int main()
{
    std::vector<bool> t1(32, false);
    for (int i = 0; i < 4; ++i) {
        t1[i] = true;
    }
    printResults(t1);
    std::bitset<32> t2("11111000000000000000000000000000");
    printResults(t2);
    std::vector<bool> t3(32, false);
    for (int i = 0; i < 12; ++i) {
        t3[i] = true;
    }
    printResults(t3);
    std::bitset<32> t4("10110000000000000000000000001000");
    printResults(t4);
    std::vector<bool> t5(32, false);
    for (int i = 1; i < 6; ++i) {
        t5[i] = true;
    }
    t5[22] = t5[31] = true;
    printResults(t5);
    return 0;
}