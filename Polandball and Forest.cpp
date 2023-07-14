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
vector<vector<int>> adj;
vector<bool> visited;
void dfs(int node)
{
    if(visited[node])
        return;
    visited[node]=true;
    for(int child: adj[node])
        dfs(child);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    adj.resize(n+1);
    visited.resize(n+1,0);
    for(int i = 0; i<n; i++)
    {
        int num;
        cin>>num;
        adj[num].push_back(i);
        adj[i].push_back(num);
    }
    int trees = 0;
    for(int i = 0; i<n; i++)
    {
        if(!visited[i])
        {
            trees++;
            dfs(i);
        }
    }
    cout<<trees;
}