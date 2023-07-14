
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
vector<bool> closed;
int nodes=0;

void dfs (int node) {
    if(visited[node]||closed[node])
        return;
    nodes++;
    visited[node]=true;
    for(auto a: adj[node])
    {
        if(!visited[a])
        {
            dfs(a);
        }
    }
};



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
    int n,m;
    cin>>n>>m;
    adj.resize(n+1);
    visited.resize(n+1);
    closed.resize(n+1,false);
    for(int i = 0; i<m; i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    if(nodes==n)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    vector<int> ord;
    for(int i = 0; i<n; i++)
    {
        int num;
        cin>>num;
        ord.push_back(num);
    }
    for(int i = 0; i<n-1; i++)
    {
        nodes = 0;
        closed[ord[i]]=true;
        visited.clear();
        visited.resize(n+1,false);
        dfs(ord[n-1]);
        if(nodes==n-i-1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}