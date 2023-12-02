#include <iostream>
#include <math.h>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <cstdio>

using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        long long n;
        cin >> n;
        vector<pair<long long, long long>> richness;
        for(int i = 0; i<n; i++)
        {
            long long a,b;
            cin>>a>>b;
            richness.push_back(make_pair(a,b));
        }
        long long l = 0;
        long long r = n+1;
        long long ans = 0;
        while(l<=r)
        {
            long long mid = (l+r)/2;
            long long c=0;
            for(int i = 0; i<n; i++)
            {
                if(mid-1-richness[i].first<=c&&c<=richness[i].second)
                    c++;
            }
            if(c>=mid)
            {
                l = mid+1;
                ans = mid;
            }
            else
                r = mid-1;

        }
        cout<<ans<<endl;
    }
}
