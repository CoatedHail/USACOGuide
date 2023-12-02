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
int n,k;
vector<vector<int>> adj;
vector<vector<long long>> dp;
long long total = 0;
void dfs(int s, int p)
{
    dp[s][0]=1;
    for(auto u:adj[s])
    {
        if(u!=p)
        {
            dfs(u,s);
            for(int i = 0; i<k; i++)
                total += dp[s][i]*dp[u][k-i-1];
            for(int i = 0; i<k; i++)
                dp[s][i+1] += dp[u][i];
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    adj.resize(n+1);
    for(int i =1; i<n; i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dp.resize(n+1,vector<long long>(k+1));
    dfs(1,-1);
    cout<<total;
}
