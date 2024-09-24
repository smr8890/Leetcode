#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    // vector<pair<int, double> > op(n);
    // for (int i = 0; i < n; ++i) {
    //     cin >> op[i].first >> op[i].second;
    // }
    vector<double> stretch(n + 1);
    vector<double> rotate(n + 1);
    stretch[0] = 1;
    for (int i = 1; i <= n; ++i) {
        int op;
        double x;
        cin >> op >> x;
        if (op == 1) {
            stretch[i] = stretch[i - 1] * x;
            rotate[i] = rotate[i - 1];
        } else {
            rotate[i] = rotate[i - 1] + x;
            stretch[i] = stretch[i - 1];
        }
    }
    while (m--) {
        int i, j;
        double x, y;
        cin >> i >> j >> x >> y;
        // for (int k = i - 1; k < j; ++k) {
        //     if (op[k].first == 1) {
        //         x *= op[k].second;
        //         y *= op[k].second;
        //     } else {
        //         double _x = x, _y = y;
        //         x = _x * cos(op[k].second) - _y * sin(op[k].second);
        //         y = _x * sin(op[k].second) + _y * cos(op[k].second);
        //     }
        // }
        x *= (stretch[j] / stretch[i - 1]);
        y *= (stretch[j] / stretch[i - 1]);
        double _x = x, _y = y;
        x = _x * cos(rotate[j] - rotate[i - 1]) - _y * sin(rotate[j] - rotate[i - 1]);
        y = _x * sin(rotate[j] - rotate[i - 1]) + _y * cos(rotate[j] - rotate[i - 1]);
        printf("%f %f\n", x, y);
    }
    return 0;
}
