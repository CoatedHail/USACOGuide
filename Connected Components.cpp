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

vector<unordered_set<int>> adj;
set<int> novis;
vector<int> sizes;
int curr = 0;
void dfs(int x)
{
    sizes[curr]++;
    auto it = novis.begin();
    while(it!=novis.end())
    {
        if(adj[x].count(*it))
            it++;
        else
        {
            int last = *it;
            novis.erase(it);
            dfs(last);
            it = novis.upper_bound(last);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    adj.resize(n);
    sizes.resize(n);
    for(int i = 0; i<m; i++)
    {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    for(int i = 0; i<n; i++)
    {
        novis.insert(i);
    }
    for(int i = 0; i<n; i++) {
        auto it = novis.find(i);
        if (it != novis.end())
        {
            novis.erase(it);
            dfs(i);
            curr++;
        }
    }
    cout<<curr<<endl;
    sort(sizes.begin(),sizes.begin()+curr);
    for(int i =0; i<curr; i++)
    {
        cout<<sizes[i]<<" ";
    }
}