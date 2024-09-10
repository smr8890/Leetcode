#include <iostream>
using namespace std;

int main() {
    int q;
    scanf("%d", &q);
    while (q--) {
        long long int n, k;
        scanf("%I64d %I64d", &n, &k);
        long long int res = 1;
        for (long long int i = 2; i <= n; ++i) {
            int t = 0;
            while (n % i == 0) {
                n /= i;
                t++;
            }
            if (t >= k) {
                while (t--) {
                    res *= i;
                }
            }
        }
        printf("%I64d\n", res);
    }
    return 0;
}
