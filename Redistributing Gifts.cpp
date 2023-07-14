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

vector<vector<int>> graph,revgraph;
vector<bool> vis,revis;
vector<int> path;
set<int> comp;
void dfs(int node)
{
    vis[node]=true;
    for(int i : graph[node])
    {
        if(!vis[i])
            dfs(i);
    }
    path.push_back(node);
}
void dfs2(int node)
{
    revis[node]=true;
    for(int i : revgraph[node])
    {
        if(!revis[i])
            dfs2(i);
    }
    comp.insert(node);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    graph.resize(n+1);
    revgraph.resize(n+1);
    vis.resize(n+1);
    revis.resize(n+1);
    for(int i = 1; i<=n; i++)
    {
        graph[i].resize(n);
        for(int j = 0; j<n; j++)
        {
            cin>>graph[i][j];
        }
        while(graph[i].back()!=i)
        {
            graph[i].pop_back();
        }
        for(int j : graph[i])
            revgraph[j].push_back(i);
    }
    for(int i = 1; i<=n; i++)
    {
        if(!vis[i])
            dfs(i);
    }
    reverse(path.begin(),path.end());
    vector<int> ans(n+1);
    for(int i : path)
    {
        if(!revis[i])
        {
            dfs2(i);
            for(int j : comp) {
                for (int k: graph[j]){
                    if(comp.count(k)>0)
                    {
                        ans[j]=k;
                        break;
                    }
                }
            }
            comp.clear();
        }
    }
    for(int i = 1; i<=n; i++)
    {
        cout<<ans[i]<<endl;
    }
}