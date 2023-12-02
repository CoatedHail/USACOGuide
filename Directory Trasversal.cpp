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

vector<vector<int>> adj;
vector<string> s;
vector<long long> sub,res,up;
long long mn = LONG_LONG_MAX;

void dfs(int v)
{
    for(int u : adj[v])
    {
        if(adj[u].empty())
        {
            res[v]+=s[u].size();
            sub[v]++;
            continue;
        }
        dfs(u);
        res[v]+=res[u]+sub[u]*(s[u].size()+1);
        sub[v]+=sub[u];
    }
}
void dfs2(int v)
{
    mn =min(mn,res[v]+up[v]);
    for(int u:adj[v])
    {
        if(!adj[u].empty())
        {
            up[u]=up[v]+res[v]-res[u]-sub[u]*(s[u].size()+1)+3*(sub[1]-sub[u]);
            dfs2(u);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("dirtraverse.in", "r", stdin);
    freopen("dirtraverse.out", "w", stdout);
    int n;
    cin>>n;
    adj.resize(n+1);
    s.resize(n+1);
    sub.resize(n+1);
    res.resize(n+1);
    up.resize(n+1,0);
    for(int i =1; i<=n; i++)
    {
        cin>>s[i];
        int k;
        cin>>k;
        while(k--)
        {
            int a;
            cin>>a;
            adj[i].push_back(a);
        }
    }
    dfs(1);
    dfs2(1);
    cout<<mn;
}