#include <cstdint>
#include <iostream>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for (int i = 0; i < 32; ++i) {
            result <<= 1;
            result |= (n & 1);
            n >>= 1;
        }
        return result;
    }
};


int main() {
    Solution my_solution;
    my_solution.reverseBits(964176192);
    return 0;
}