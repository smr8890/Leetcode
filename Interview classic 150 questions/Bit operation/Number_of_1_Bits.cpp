#include <iostream>
#include <bitset>
using namespace std;

class Solution {
public:
    int hammingWeight(int n) {
        return bitset<32>(n).count();
    }
};