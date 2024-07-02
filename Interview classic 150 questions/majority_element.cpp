#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len=nums.size();
        if (len==1) {
            return nums[0];
        }
        int n=len/2;
        sort(nums.begin(), nums.end());
        int count=1;
        for (int i = 1; i < len; ++i) {
            if (nums[i]==nums[i-1]) {
                count++;
                if (count>n) {
                    return nums[i];
                }
            }else {
                count=1;
            }
        }
        return 0;
    }
};