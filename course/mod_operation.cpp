#include <iostream>
using namespace std;

long long int fast_power(long long int b, long long int p, long long int k) {
    long long int result = 1;
    while (p > 0) {
        if (p % 2 == 1) {
            result = result * b % k;
        }
        p /= 2;
        b = b * b % k;
    }
    return result % k;
}

int main() {
    long long int b, p, k;
    cin >> b >> p >> k;
    long long int res = fast_power(b, p, k);
    cout << b << '^' << p << " mod " << k << '=' << res << endl;
    return 0;
}
