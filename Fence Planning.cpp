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

struct Cow{
    int x,y;
    vector<int> adj;
    bool visited;
};
vector<Cow> cows;
vector<int> curr_net;

void dfs(int curr)
{
    cows[curr].visited = true;
    curr_net.push_back(curr);
    for(int i : cows[curr].adj)
    {
        if(!cows[i].visited)
            dfs(i);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);
    int n,m;
    cin>>n>>m;
    cows.resize(n);
    for(int i = 0; i<n; i++)
    {
        int a,b;
        cin>>a>>b;
        cows[i].x =a;
        cows[i].y = b;
    }
    for(int i = 0; i<m; i++)
    {
        int a,b;
        cin>>a>>b;
        cows[a-1].adj.push_back(b-1);
        cows[b-1].adj.push_back(a-1);
    }
    int smallest = INT_MAX;
    for(int i = 0; i<n; i++) {
        curr_net.clear();
        if(cows[i].visited)
            continue;
        dfs(i);

        int minx, miny, maxx, maxy;
        minx=miny=INT_MAX;
        maxx=maxy=-1;
        for (auto p: curr_net)
        {
            minx=min(minx,cows[p].x);
            miny=min(miny,cows[p].y);
            maxx=max(maxx,cows[p].x);
            maxy=max(maxy,cows[p].y);
        }
        smallest = min(smallest,(maxy-miny+maxx-minx)*2);
    }
    cout<<smallest;
}