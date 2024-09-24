#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<string, int> map;
    for (int i = 0; i < n; ++i) {
        string s, t;
        for (int j = 0; j < 8; ++j) {
            cin >> t;
            s += t;
        }
        map[s]++;
        cout << map[s]<<endl;
    }
    return 0;
}
