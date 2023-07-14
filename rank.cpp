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
int counts = 0;
vector<bool> visited;
bool done = false;
void dfs(int node,int initial)
{
    visited[node]=true;
    for(auto a:adj[node])
    {
        if(a==initial)
        {
            counts++;
            done = true;
            return;
        }
        if(visited[a]!=true)
            dfs(a,initial);
        if(done)
            return;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    visited.resize(n);
    adj.resize(n);
    for(int i = 0; i<k; i++)
    {
        int a,b,sa,sb;
        cin>>a>>b>>sa>>sb;
        if(sa>sb)
        {
            adj[a-1].push_back(b-1);
        }
        else
            adj[b-1].push_back(a-1);
    }
    for(int i = 0; i<n; i++)
    {
        visited.clear();
        visited.resize(n);
        done = false;
        dfs(i,i);
    }
    cout<<counts;
}