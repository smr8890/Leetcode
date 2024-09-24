#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, d;
    cin >> n >> d;
    vector<vector<int> > Q(n, vector<int>(d)), KT(d, vector<int>(n)), V(n, vector<int>(d));
    vector<int> W(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < d; ++j) {
            cin >> Q[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < d; ++j) {
            cin >> KT[j][i];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < d; ++j) {
            cin >> V[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        cin >> W[i];
    }

    vector<vector<long long int> > tmp(n, vector<long long int>(n));
    vector<vector<long long int> > tmp1(n, vector<long long int>(d));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < d; ++k) {
                tmp[i][j] += Q[i][k] * KT[k][j];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            tmp[i][j] = tmp[i][j] * W[i];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < d; ++j) {
            for (int k = 0; k < n; ++k) {
                tmp1[i][j] += tmp[i][k] * V[k][j];
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < d; ++j) {
            cout << tmp1[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
