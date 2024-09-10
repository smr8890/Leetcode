#include <iostream>
#include <vector>
using namespace std;

int search(vector<int> &nums, int target) {
    int left = 0, right = nums.size() - 1;
    int count = 0;
    while (left <= right) {
        count++;
        int mid = (left + right) / 2;
        if (nums[mid] == target)return count;
        if (nums[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return 0;
}

int main() {
    int n, data;
    cin >> n >> data;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    cout << search(nums, data) << endl;
    return 0;
}
