#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Activity {
    int start;
    int end;
};

bool cmp(Activity a,Activity b) {
    return a.end<b.end;
}

int main() {
    int n;
    cin>>n;
    vector<Activity>activities(n);
    for (int i = 0; i < n; ++i) {
        cin>>activities[i].start>>activities[i].end;
    }
    sort(activities.begin(),activities.end(),cmp);
    int cur=0,res=0;
    for (int i = 0; i < n; ++i) {
        if (activities[i].start>=cur) {
            cur=activities[i].end;
            res++;
        }
    }
    cout<<res<<endl;
    return 0;
}