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

int MOD = 1000000007;
vector<vector<int>> adj;
vector<vector<long long>> dp;
void dfs(int s, int p)
{
    dp[s][0]=1;
    dp[s][1]=1;
    for(auto u:adj[s])
    {
        if(u!=p) {
            dfs(u,s);
            dp[s][0]=(dp[s][0]*(dp[u][0]+dp[u][1]))%MOD;
        }
    }
    for(auto u:adj[s])
    {
        if(u!=p)
        {
            dp[s][1]=(dp[s][1]*dp[u][0])%MOD;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    adj.resize(n+1);
    for(int i = 1; i<n; i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dp.resize(n+1,vector<long long>(2));
    dfs(1,-1);
    cout<<(dp[1][0]+dp[1][1])%MOD;

}
