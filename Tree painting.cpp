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

using namespace std;

long long n,ans;
vector<int> siz;
vector<long long> dp;
vector<vector<int>> g;

int calcsize(int v, int p)
{
    siz[v]=1;
    for(auto child : g[v])
    {
        if(child!=p)
            siz[v]+=calcsize(child,v);
    }
    return siz[v];
}
long long calcdp(int v, int p)
{
    dp[v]=siz[v];
    for(auto child: g[v]) {
        if (child != p)
            dp[v] += calcdp(child, v);
    }
    return dp[v];
}

void dfs(int v, int p)
{
    ans = max(ans,dp[v]);
    for(auto child : g[v])
    {
        if(child==p) continue;
        dp[v]-=dp[child];
        dp[v]-=siz[child];
        siz[v]-=siz[child];
        siz[child]+=siz[v];
        dp[child]+=siz[v];
        dp[child]+=dp[v];

        dfs(child,v);

        dp[child]-=dp[v];
        dp[child]-=siz[v];
        siz[child]-=siz[v];
        siz[v]+=siz[child];
        dp[v]+=siz[child];
        dp[v]+=dp[child];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    g.resize(n);
    for(int i = 0; i<n-1; i++)
    {
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    ans=0;
    siz.resize(n);
    dp.resize(n);
    calcsize(0,-1);
    calcdp(0,-1);
    dfs(0,-1);
    cout<<ans;
}