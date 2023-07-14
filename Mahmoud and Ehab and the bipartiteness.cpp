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

vector<vector<int>> adj;
long long c=0,uc=0;

void dfs(int node, int parent,bool color)
{
    if(color == true)
        c++;
    else
        uc++;
    for(int u : adj[node])
    {
        if(u!=parent)
        {
            dfs(u,node,!color);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    adj.resize(n+1);
    for(int i = 0; i<n-1; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0,true);
    cout<<c*uc-(n-1);
}