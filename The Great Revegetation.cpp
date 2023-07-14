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

int connect=0;
bool impossible = false;
vector<pair<int,char>> adj[100001];
bool visited[100001];
bool color[100001];

void dfs(int u,bool g)
{
    visited[u]=true;
    color[u]=g;
    for(auto x:adj[u])
    {
        if(visited[x.first])
        {
            if(x.second=='S'&&color[x.first]!=g)
            {
                impossible = true;
            }
            if(x.second=='D'&&color[x.first]==g)
                impossible = true;
        }
        if(!visited[x.first])
        {
            if(x.second=='S')
            {
                dfs(x.first,g);
            }
            if(x.second=='D')
                dfs(x.first,!g);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);
    int n,m;
    cin>>n>>m;
    for(int i = 0; i<m; i++)
    {
        char a;
        int b,c;
        cin>>a>>b>>c;
        adj[b].push_back(make_pair(c,a));
        adj[c].push_back(make_pair(b,a));
    }
    for(int i = 1; i<=n; i++)
    {
        if(!visited[i])
        {
            connect++;
            dfs(i,0);
        }
        if(impossible)
        {
            cout<<0;
            return 0;
        }
    }
    cout<<1;
    for(int i = 0; i<connect; i++)
        cout<<0;
}