#include <iostream>
#include <math.h>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <cstdio>

using namespace std;

long long n;
vector<long long> heaps;

bool check(long long x) {
    vector<long long> cur_h(heaps.begin(), heaps.begin() + n);
    for (int i = n - 1; i >= 2; --i) {
        if (cur_h[i] < x) return false;
        int d = min(heaps[i], cur_h[i] - x) / 3;
        cur_h[i - 1] += d;
        cur_h[i - 2] += 2 * d;
        // we don't need to fix cur_h[i] since we are not going back
    }
    return cur_h[0] >= x and cur_h[1] >= x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        long long maxy = 0;
        cin>>n;
        heaps.resize(n);
        long long ans = LONG_LONG_MAX;
        for(int i =0; i<n; i++)
        {
            cin>>heaps[i];
            maxy = max(maxy,heaps[i]);
            ans = min(ans,heaps[i]);
        }
        int l = 0;
        int r = maxy;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(check(mid)) {
                ans = mid;
                l = mid+1;
            }
            else r= mid-1;
        }
        cout<<ans<<endl;
    }
}