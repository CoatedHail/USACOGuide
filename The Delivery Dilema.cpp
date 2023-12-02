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
        int n;
        cin>>n;
        vector<int> a(n),b(n);
        for(int i = 0; i<n; i++)
            cin>>a[i];
        for(int i = 0; i<n; i++)
            cin>>b[i];
        long long l = 0;
        long long r = LONG_LONG_MAX;
        long long ans =0;
        while(l<=r)
        {
            long long mid = (l+r+1)/2;
            long long count = 0;
            for(int i = 0; i<n; i++)
            {
                if(mid<a[i])
                    count+=b[i];
            }
            if(count<=mid)
            {
                ans = mid;
                r = mid-1;
            }
            else
                l = mid+1;
        }
        cout<<ans<<endl;
    }
}
