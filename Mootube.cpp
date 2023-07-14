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

vector<vector<pair<int,int>>> neighbors;
vector<bool> visited;
int reachable,threshold;
void dfs(int node)
{
    visited[node]=true;
    for(auto x:neighbors[node]) {
        if(!visited[x.first]&&x.second>=threshold)
        {
            reachable++;
            dfs(x.first);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    int n,q;
    cin>>n>>q;
    neighbors.resize(n+1);
    for(int i = 0; i<n-1; i++)
    {
        int a,b,w;
        cin>>a>>b>>w;
        neighbors[a].push_back(make_pair(b,w));
        neighbors[b].push_back(make_pair(a,w));
    }
    for(int i = 0; i<q; i++)
    {
        int start;
        cin>>threshold>>start;
        reachable = 0;
        visited.clear();
        visited.resize(n+1);
        dfs(start);
        cout<<reachable<<endl;
    }
}
