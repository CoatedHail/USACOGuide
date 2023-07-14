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
vector<pair<int,int>> rtb;

void dfs (int node) {
    if (visited[node]) return;
    visited[node] = true;
    for (auto neighbor : adj[node])
        dfs(neighbor);
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    visited.resize(n+1);
    adj.resize(n+1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            adj[1].push_back(i);
            adj[i].push_back(1);
            rtb.push_back(make_pair(1,i));
            dfs(i);
        }
    }
    cout<<rtb.size()<<endl;
    for(pair<int,int> p:rtb)
    {
        cout<<p.first<<" "<<p.second<<endl;
    }
}