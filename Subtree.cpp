#include <iostream>
#include <math.h>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cstdio>
#define int long long

using namespace std;

int n,m;
vector<int> dp,dp2;
vector<vector<int>> adj;
vector<vector<int>> ps,ss;

void dfs(int u, int p)
{
    dp[u]=1;
    for(int i = 0; i<=adj[u].size()+3; i++)
    {
        ps[u].push_back(1);
        ss[u].push_back(1);
    }
    for(int i = 1; i<=adj[u].size(); i++)
    {
        int child = adj[u][i-1];
        ps[u][i]=ps[u][i-1];
        if(child==p) continue;
        dfs(child,u);
        dp[u]*=(1+dp[child]);
        dp[u]%=m;
        ps[u][i]*=(1+dp[child]);
        ps[u][i]%=m;
    }
    for(int i = adj[u].size(); i>=1; i--)
    {
        int child = adj[u][i-1];
        ss[u][i]=ss[u][i+1];
        if(child==p) continue;
        ss[u][i]*=(1+dp[child]);
        ss[u][i]%=m;
    }
}
void dfs2(int u,int p)
{
    for(int i = 1; i<=adj[u].size(); i++)
    {
        int child = adj[u][i-1];
        if(child!=p) {
            dp2[child] = ((ps[u][i - 1] * ss[u][i + 1]) % m * dp2[u] % m + 1) % m;
            dfs2(child, u);
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    adj.assign(n + 10,vector<int>());
    dp.resize(n+10);
    dp2.resize(n+10);
    ps.resize(n+10);
    ss.resize(n+10);
    for (int i=0; i<n-1; i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,-1);
    dp2[1] = 1;
    dfs2(1,-1);
    for (int i=1; i<=n; i++){
        cout<<(dp[i] * dp2[i]) % m<<endl;
    }
}