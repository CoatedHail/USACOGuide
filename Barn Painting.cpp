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
    for(auto u:adj[s])
    {
        if(u!=p) {
            dfs(u,s);
            dp[s][0]=(dp[s][0]*(dp[u][1]+dp[u][2]))%MOD;
            dp[s][1]=(dp[s][1]*(dp[u][0]+dp[u][2]))%MOD;
            dp[s][2]=(dp[s][2]*(dp[u][1]+dp[u][0]))%MOD;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("barnpainting.in", "r", stdin);
    freopen("barnpainting.out", "w", stdout);
    int n,m;
    cin>>n>>m;
    adj.resize(n+1);
    for(int i = 1; i<n; i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dp.resize(n+1,vector<long long>(3));
    for (int i = 1; i <= n; i++) dp[i][0] = 1, dp[i][1] = 1, dp[i][2] = 1;
    for(int i = 0; i<m; i++)
    {
        int b, c;
        cin >> b >> c;
        dp[b][0] = 0;
        dp[b][1] = 0;
        dp[b][2] = 0;
        dp[b][c - 1] = 1;
    }
    dfs(1,-1);
    cout << (dp[1][0] + dp[1][1] + dp[1][2]) % MOD;
}
