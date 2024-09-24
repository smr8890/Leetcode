#include <iostream>
using namespace std;

int main() {
    long long int b, p, k;
    cin >> b >> p >> k;
    long long int result = 1, base = b, power = p;
    base = base % k;
    while (power > 0) {
        if (power % 2 == 1) {
            result = result * base % k;
        }
        power /= 2;
        base = base * base % k;
    }
    cout << b << '^' << p << " mod " << k << '=' << result << endl;
    return 0;
}
