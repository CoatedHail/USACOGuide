
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

vector<vector<int>> adj;
vector<bool> visited;
vector<int> which;
bool imp=false;

void dfs (int node) {
    if(imp) return;
    visited[node]=true;
    for(auto a: adj[node])
    {
        if(!visited[a])
        {
            if(which[node]==1) which[a]=2;
            else
                which[a]=1;
            dfs(a);
        }
        else
        {
            if(which[node]==which[a])
            {
                imp=true;
                return;
            }
        }
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    adj.resize(n+1);
    visited.resize(n+1);
    which.resize(n+1);
    for(int i = 0; i<m; i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    which[1]=1;
    dfs(1);
    for(int i = 1; i<=n; i++)
    {
        if(!visited[i])
        {
            if(imp){
                cout<<"IMPOSSIBLE"<<endl;
                return 0;
            }
            which[i]=1;
            dfs(i);
        }
    }
    for(int i = 1; i<=n; i++)
    {
        cout<<which[i]<<" ";
    }
}