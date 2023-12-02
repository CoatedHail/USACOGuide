#include <iostream>
#include <math.h>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cstdio>

using namespace std;

const int mod = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        long long n,m;
        cin>>n>>m;
        for(int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i % 2 == 0) cout << (n / 2 + i / 2) * m + j + 1 << ' ';
                else cout << (i / 2) * m + j + 1 << ' ';
            }
            cout<<endl;
        }
    }
}
