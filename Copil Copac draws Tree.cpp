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

const int mod = 1e9+7;

vector<int> dp,id;
vector<vector<pair<int,int>>> edge;

void dfs(int u)
{
    for(auto x: edge[u])
    {
        if(dp[x.first]==0)
        {
            dp[x.first]=dp[u]+(x.second<=id[u]);
            id[x.first]=x.second;
            dfs(x.first);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        dp.resize(n+1);
        id.resize(n+1);
        edge.resize(n+1);
        for(int i = 1; i<=n; i++)
        {
            dp[i]=id[i]=0;
            edge[i].clear();
        }
        for(int i = 1; i<n; i++)
        {
            int u,v;
            cin>>u>>v;
            edge[u].push_back({v,i});
            edge[v].push_back({u,i});
        }
        dp[1]=1;
        dfs(1);
        int ans = 0;
        for(int i = 1; i<=n; i++)
            ans=max(ans,dp[i]);
        cout<<ans<<endl;
    }
}
