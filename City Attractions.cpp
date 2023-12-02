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

vector<int> a;
vector<vector<int>> nxt,graph;
vector<pair<int,int>> dp,pdp;


void dfs(int u, int p)
{
    dp[u]={INT_MAX/2,0};
    for(int i : graph[u])
    {
        if(i!=p)
        {
            dfs(i,u);
            dp[u]=min({dp[u], {dp[i].first + 1, dp[i].second}, {1 - a[i], i}});
        }
    }
}
void dfs2(int u,int p)
{
    dp[u]=min(dp[u],pdp[u]);
    pair<int,int> tmp = {pdp[u].first + 1, pdp[u].second};
    tmp = min(tmp,{1-a[u],u});
    for(int i: graph[u])
    {
        if(i!=p)
        {
            pdp[i]=min(pdp[i],tmp);
            tmp = min({tmp,{dp[i].first + 2, dp[i].second}, {2 - a[i], i}});
        }
    }
    reverse(graph[u].begin(), graph[u].end());
    tmp = {pdp[u].first + 1, pdp[u].second};
    tmp = min(tmp, {1 - a[u], u});
    for (int i : graph[u])
        if (i != p) {
            pdp[i] = min(pdp[i], tmp);
            tmp = min({tmp, {dp[i].first + 2, dp[i].second}, {2 - a[i], i}});
        }
    for (int i : graph[u])
        if (i != p) dfs2(i, u);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    long long k;
    cin>>n>>k;
    for(int i = 1; i<=n; i++)
    {
        cin>>a[i];
        pdp[i]={INT_MAX/2,0};
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1,-1);
    dfs2(1,-1);
    for (int i = 1; i <= n; i++) nxt[0][i] = dp[i].second;
    int curr = (k & 1 ? nxt[0][1] : 1);
    for (int i = 1; i < 63; i++) {
        for (int j = 1; j <= n; j++)
            nxt[i & 1][j] = nxt[i - 1 & 1][nxt[i - 1 & 1][j]];
        if (k & (1ll << i)) curr = nxt[i & 1][curr];
    }
    cout << curr << '\n';
}