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
#include <iomanip>
#include <numeric>
using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("time.in","r",stdin);
    freopen("time.out","w",stdout);
    int n,m,c;
    cin>>n>>m>>c;
    vector<int> money;
    for(int i = 0; i<n; i++)
    {
        int num;
        cin>>num;
        money.push_back(num);
    }
    vector<vector<int>> adj(n);
    for(int i = 0; i<m; i++)
    {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        adj[a].push_back(b);
    }
    vector<vector<int>> dp(1001,vector<int> (n,-1));
    dp[0][0]=0;
    int ans = 0;
    for(int d = 0; d<1000; d++)
    {
        for(int i = 0; i<n; i++)
        {
            if(dp[d][i]!=-1)
            {
                for(auto x:adj[i])
                {
                    dp[d+1][x]=max(dp[d+1][x],dp[d][i]+money[x]);
                }
            }
        }
        ans = max(ans,dp[d][0]-c*d*d);
    }
    cout<<ans;
}