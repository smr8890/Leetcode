#include<vector>
using namespace std;

class Solution {
public:
    int hIndex(vector<int> &citations) {
        int len = citations.size();
        int h = 0;
        while (h <= len) {
            int count = 0;
            for (int i = 0; i < len; ++i) {
                if (citations[i] > h) {
                    count++;
                }
            }
            if (count <= h) {
                break;
            }
            h++;
        }
        return h;
    }
};
