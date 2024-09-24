#include <iostream>
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    int res = 0;
    while (n--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 >= a)continue;
        if (x1 < 0)x1 = 0;
        if (y1 >= b)continue;
        if (y1 < 0)y1 = 0;
        if (x2 <= 0)continue;
        if (x2 > a)x2 = a;
        if (y2 <= 0)continue;
        if (y2 > b)y2 = b;
        res += (x2 - x1) * (y2 - y1);
    }
    cout << res << endl;
    return 0;
}
