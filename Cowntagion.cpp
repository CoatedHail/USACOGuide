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

int maxn=100005;
vector<vector<int>> adj(maxn);
int dfs(int start, int parent)
{
    int ans = 0;
    int cows = adj[start].size();
    if(parent==-1)
    {
        cows++;
    }
    int curr = 1;
    int days = 0;
    while(curr<cows)
    {
        days++;
        curr*=2;
    }
    ans+=days;
    for(auto child : adj[start])
    {
        if(child!=parent)
            ans+=dfs(child,start)+1;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i = 0; i<n-1; i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout<<dfs(1,-1);
}
