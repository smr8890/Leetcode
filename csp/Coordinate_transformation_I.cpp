#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int> > op(n);
    vector<pair<int, int> > coordinate(m);
    for (int i = 0; i < n; ++i) {
        cin >> op[i].first >> op[i].second;
    }
    for (int i = 0; i < m; ++i) {
        cin >> coordinate[i].first >> coordinate[i].second;
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            coordinate[i].first += op[j].first;
            coordinate[i].second += op[j].second;
        }
        cout << coordinate[i].first << ' ' << coordinate[i].second << endl;
    }
    return 0;
}
