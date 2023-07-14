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

int MAXN = 250;
int n,b;
vector<vector<bool>> visited(MAXN, vector<bool>(MAXN));
vector<int> tiles(MAXN);
vector<pair<int,int>> shoes(MAXN);

int ans = INT_MAX;

void dfs(int depth, int boot)
{
    if(visited[depth][boot])
        return;
    visited[depth][boot]=true;
    if(depth == n-1)
    {
        ans = min(boot,ans);
        return;
    }
    for(int i = depth+1; i<=depth+shoes[boot].second&&i<n; i++)
    {
        if(tiles[i]<=shoes[boot].first)
        {
            dfs(i,boot);
        }
    }
    for(int i = boot; i<b; i++)
    {
        if(tiles[depth]<=shoes[i].first)
            dfs(depth,i);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("snowboots.in", "r", stdin);
    freopen("snowboots.out", "w", stdout);
    cin>>n>>b;
    for(int i = 0; i<n; i++)
    {
        cin>>tiles[i];
    }
    for(int i = 0; i<b; i++)
    {

        cin>>shoes[i].first>>shoes[i].second;
    }
    dfs(0,0);
    cout<<ans;
}

