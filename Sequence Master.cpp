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
    long long t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        long long ans = 0, sum = 0;
        vector<long long> v(n*2+1);
        for(int i = 1; i<=n*2; i++)
        {
            cin>>v[i];
            ans +=abs(v[i]);
            sum+=abs(v[i]-(-1));
        }
        if(n==1)
            ans = min(ans, abs(v[1]-v[2]));
        if(n==2)
        {
            ans = min(ans, abs(v[1]-2)+abs(v[2]-2)+abs(v[3]-2)+abs(v[4]-2));
        }
        if(n%2==0)
        {
            for(int i = 1; i<=n*2; i++)
            {
                ans=min(ans,sum-abs(v[i]-(-1))+abs(v[i]-n));
            }
        }
        cout<<ans<<endl;
    }
}

