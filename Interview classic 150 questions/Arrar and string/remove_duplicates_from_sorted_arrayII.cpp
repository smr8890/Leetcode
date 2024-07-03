#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len=nums.size();
        int count=1;
        for (int i=0,j=1;j<nums.size();j++) {
            if (nums[i]==nums[j]) {
                count++;
                if (count>2) {
                    nums[j]=INT_MAX;
                    len--;
                }
            }else {
                i=j;
                count=1;
            }
        }
        sort(nums.begin(), nums.end());
        return len;
    }
};