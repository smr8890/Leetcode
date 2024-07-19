#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int len = numbers.size();
        vector<int> index(2);
        int left = 0, right = len - 1;
        while (left <= right) {
            if (numbers[left] + numbers[right] > target) {
                right--;
            } else if (numbers[left] + numbers[right] < target) {
                left++;
            } else {
                index[0] = left + 1;
                index[1] = right + 1;
                break;
            }
        }
        return index;
    }
};
