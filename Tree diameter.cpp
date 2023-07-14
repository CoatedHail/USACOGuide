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

int n;
vector<vector<int>> adj(n+1);
int dis,e;
void dfs(int u,int p,int depth)
{
    for(int v:adj[u])
    {
        if(v==p)
            continue;
        dfs(v,u,depth+1);
    }
    if(depth>dis) {

        dis = depth;
        e = u;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    adj.resize(n+1);
    for(int i =1; i<n; i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,-1,0);
    dis = 0;
    dfs(e,-1,0);
    cout<<dis;
}
