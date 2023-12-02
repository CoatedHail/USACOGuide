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

vector<vector<long long>> dp,A,adj;

void dfs(int v, int p)
{
    dp[0][v]=dp[1][v]=0;
    for(int u: adj[v])
    {
        if(u==p)
            continue;
        dfs(u,v);
        dp[0][v]+=max(abs(A[0][v]-A[1][u])+dp[1][u],dp[0][u] + abs(A[0][v] - A[0][u]));
        dp[1][v]+=max(abs(A[1][v] - A[1][u]) + dp[1][u], dp[0][u] + abs(A[1][v] - A[0][u]));
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        dp.clear();
        A.clear();
        adj.clear();
        dp.resize(2,vector<long long>(n+1)),A.resize(2,vector<long long>(n+1)),adj.resize(n+1);
        for(int i = 1; i<=n; i++)
        {
            cin>>A[0][i]>>A[1][i];
        }
        for(int i = 1; i<n; i++)
        {
            long long u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1,-1);
        cout<<max(dp[0][1],dp[1][1])<<endl;
    }
}
