#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len=nums.size();
        for (int i=0,j=1;j<nums.size();j++) {
            if (nums[j]==nums[i]) {
                nums[j]=INT_MAX;
                len--;
            }else {
                i=j;
            }
        }
        sort(nums.begin(),nums.end());
        return len;
    }
};