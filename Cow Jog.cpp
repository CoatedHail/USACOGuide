#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"
#include "set"
#include "unordered_set"
#include "stack"
#include "map"
#include "limits.h"
#include "cstdio"
#include "math.h"
#include <numeric>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("cowjog.in", "r", stdin);
    freopen("cowjog.out", "w", stdout);
    int n,t;
    cin>>n>>t;
    vector<long long> A;
    for(int i = 0; i<n; i++) {
        long long x, s;
        cin >> x >> s;
        x = -(x + s * t);
        if (A.empty() || x >= A.back()) {
            A.push_back(x);
        } else
        {
            *upper_bound(A.begin(),A.end(),x)=x;
        }
    }
    cout<<A.size();
}
