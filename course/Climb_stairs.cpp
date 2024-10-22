#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    while (cin>>n) {
        if (n==1) {
            cout<<1<<endl;
            continue;
        }
        vector<int>dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        for (int i = 2; i <= n; ++i) {
            dp[i]=dp[i-1]+dp[i-2];
        }
        cout<<dp[n]<<endl;
    }
    return 0;
}
