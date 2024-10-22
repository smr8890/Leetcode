#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int V;
    cin >> V;
    int n;
    cin >> n;
    vector<int> vs(n);
    for (int i = 0; i < n; ++i) {
        cin >> vs[i];
    }

    vector<int> dp(V + 1, 0);

    for (int i = 0; i < n; ++i) {
        for (int j = V; j >= vs[i]; --j) {
            dp[j] = max(dp[j], dp[j - vs[i]] + vs[i]);
        }
    }
    cout << V-dp[V] << endl;
    return 0;
}
