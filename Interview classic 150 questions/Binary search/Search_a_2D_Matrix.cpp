#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        if (m == 1) {
            for (int i = 0; i < n; ++i) {
                if (matrix[0][i] == target)return true;
            }
        } else {
            int left = 0, right = m * n - 1;
            while (left <= right) {
                int mid = (left + right) / 2;
                int i = mid / n, j = mid % n;
                if (matrix[i][j] < target) {
                    left = mid + 1;
                } else if (matrix[i][j] > target) {
                    right = mid - 1;
                } else {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    vector<vector<int> > test({{1}, {3}});
    Solution my_solution;
    my_solution.searchMatrix(test, 2);
    std::cout << 1 / 1;
    return 0;
}
