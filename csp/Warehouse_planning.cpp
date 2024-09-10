#include <iostream>
#include <vector>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int> > warehouse(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> warehouse[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        int j;
        for (j = 0; j < n; ++j) {
            bool flag = true;
            for (int k = 0; k < m; ++k) {
                if (warehouse[j][k] <= warehouse[i][k]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                cout << j + 1 << '\n';
                break;
            }
        }
        if (j == n) {
            cout << 0 << '\n';
        }
    }
    return 0;
}
