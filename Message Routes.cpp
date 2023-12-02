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
#include <numeric>
using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i =0 ; i<m; i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue<int> q;
    vector<int> dist(n+1,INT_MAX),parent(n+1);
    dist[1]=0;
    q.push(1);
    while(!q.empty())
    {
        int top = q.front();
        q.pop();
        for(int t : adj[top])
        {
            if(dist[t]==INT_MAX)
            {
                dist[t]=dist[top]+1;
                parent[t]=top;
                q.push(t);
            }
        }
    }
    if(dist[n]==INT_MAX)
        cout<<"IMPOSSIBLE";
    else
    {
        cout<<dist[n]+1<<endl;
        vector<int> v;
        v.push_back(n);
        while(true)
        {
            if(v.back()==1)
                break;
            v.push_back(parent[v.back()]);
        }
        reverse(v.begin(),v.end());
        for(int x: v)
            cout<<x<<" ";
    }

}