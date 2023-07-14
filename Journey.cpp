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
vector<bool> visited;

double ans=0.0;
void dfs(int node, int currlength, double probab)
{
    visited[node]=true;
    int moves = 0;
    for(int x: adj[node])
    {
        if(!visited[x])
            moves++;
    }
    if(moves==0)
    {
        ans+=currlength*probab;
    }
    else
    {
        double newprob = probab/moves;
        for(int x: adj[node])
        {
            if(!visited[x])
                dfs(x,currlength+1,newprob);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    adj.resize(n+1);
    visited.resize(n+1);
    for(int i = 1; i<n; i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0,1);
    cout<<setprecision(10)<<ans;
}
