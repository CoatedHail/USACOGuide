#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"
#include "set"
#include "stack"
#include "map"
#include "limits.h"
#include "cstdio"
#include "math.h"
#include <iomanip>
#include <numeric>
using namespace std;

vector<int> adj[100005][2];
vector<bool> visited;
void dfs(int v,int x)
{
    visited[v]=true;
    for(auto a:adj[v][x])
    {
        if(visited[a]!=true)
            dfs(a,x);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    visited.resize(n+1,false);
    for(int i = 0; i<m; i++)
    {
        long long a,b;
        cin>>a>>b;
        adj[a][1].push_back(b);
        adj[b][2].push_back(a);
    }
    dfs(1,1);
    for(int i = 1; i<=n; i++)
    {
        if(!visited[i])
        {
            cout<<"NO"<<endl;
            cout<<1<<" "<<i<<endl;
            return 0;
        }
    }
    visited.clear();
    visited.resize(n+1,false);
    dfs(1,2);
    for(int i = 1; i<=n; i++)
    {
        if(!visited[i])
        {
            cout<<"NO"<<endl;
            cout<<i<<" "<<1<<endl;
            return 0;
        }
    }
    cout<<"YES";
}