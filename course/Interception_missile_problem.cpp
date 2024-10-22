#include <iostream>
#include <vector>
using namespace std;

int main() {
    int highs[1005];
    bool flags[1005];
    int n=0;
    while(cin>>highs[n]){
        n++;
        if (cin.get()==EOF)break;
    }
    int k=0,intercept=0;
    while (intercept<n) {
        int cur=50000;
        for (int i = 0; i < n; ++i) {
            if (!flags[i]&&highs[i]<cur) {
                cur=highs[i];
                flags[i]=true;
                intercept++;
            }
        }
        k++;
    }
    cout<<k<<endl;
    return 0;
}