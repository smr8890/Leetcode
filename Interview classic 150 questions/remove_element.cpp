#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len=nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i]==val) {
                nums[i]=INT_MAX;
                len--;
            }
        }
        sort(nums.begin(),nums.end());
        return len;
    }
};