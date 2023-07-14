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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
    int n,m;
    cin>>n>>m;
    vector<char> farms(n+1,-1);
    for(int i =0 ; i<n; i++)
    {
        cin>>farms[i+1];
    }
    vector<vector<int>> adj(n+1);
    for(int i = 0; i<n-1; i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int numcomp = 0;
    vector<int> comp(n+1,-1);
    for(int i = 1; i<=n; i++)
    {
        if(comp[i]!=-1)
            continue;
        stack<int> frontier;
        frontier.push(i);
        char type = farms[i];
        while(!frontier.empty())
        {
            int curr = frontier.top();
            frontier.pop();
            comp[curr]=numcomp;
            for(int x: adj[curr])
            {
                if(farms[x]==type &&comp[x]==-1)
                {
                    frontier.push(x);
                }
            }
        }
        numcomp++;
    }
    for(int i = 0; i<m; i++)
    {
        int a,b;
        char milk;
        cin>>a>>b>>milk;
        if(comp[a]==comp[b])
        {
            if(farms[a]==milk)
                cout<<1;
            else
                cout<<0;
        }
        else
            cout<<1;
    }
}