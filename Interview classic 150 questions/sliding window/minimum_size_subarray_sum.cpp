#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int len = nums.size();
        int sum=0,min_len=INT_MAX;
        int left=0,right=0;
        while (right<len) {
            sum+=nums[right];
            while (sum>=target) {
                min_len=min(min_len,right-left+1);
                sum-=nums[left];
                left++;
            }
            right++;
        }
        if (min_len<=len) {
            return min_len;
        }
        return 0;
    }
};

int main() {
    Solution mysolution;
    vector<int>test={1,2,3,4,5};
    cout<<mysolution.minSubArrayLen(15,test)<<endl;
    return 0;
}