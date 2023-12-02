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



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int n, x;
        cin>>n>>x;
        vector<int> v(n);
        for(int i = 0; i<n; i++)
            cin>>v[i];
        if(is_sorted(v.begin(),v.end()))
        {
            cout<<0<<endl;
            continue;
        }
        vector<vector<int>> dp(n,vector<int>(501,INT_MAX));
        for(int i = 0; i<n; i++)
        {
            if(v[i]>x&&(i==0||v[i-1]<=x))
                dp[i][x]=1;
            if(i<n-1&&v[i]>v[i+1])
                break;
        }
        int ans = INT_MAX;
        for(int i = 0; i<n; i++)
        {
            for(int j =0; j<=500; j++)
            {
                if(dp[i][j]==INT_MAX)
                    continue;
                if(i==n||(j <= v[i + 1] && is_sorted(v.begin() + i + 1, v.end())))
                    ans = min(ans,dp[i][j]);
                bool good = true;
                for(int k = i+1; k<n; k++)
                {
                    int pr = k==i+1?j:v[k-1];
                    if(good&&v[i]>=pr&&v[i]<v[k])
                        dp[k][v[i]]=min(dp[k][v[i]],dp[i][j]+1);
                    good &= v[k]>=pr;
                }
            }
        }
        if(ans == INT_MAX)
            cout<<-1<<endl;
        else
            cout<<ans<<endl;
    }
}
