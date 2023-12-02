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

struct DSU {
    vector<int> e;

    DSU(int N) : e(N, -1) {}

    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

    bool connected(int a, int b) { return get(a) == get(b); }

    int size(int x) { return -e[get(x)]; }

    bool unite(int x, int y) {
        x = get(x), y = get(y);
        if (x == y) { return false; }
        if (e[x] > e[y]) { swap(x, y); }
        e[x] += e[y];
        e[y] = x;
        return true;
    }
};
long long kruskal(int N, vector<pair<long long, pair<int, int>>> edges)
{
    sort(edges.begin(),edges.end());
    long long ans = 0;
    DSU dsu(N+1);
    for(pair<long long,pair<int,int>> &e: edges)
    {
        if(dsu.unite(e.second.first,e.second.second)) ans+=e.first;
    }
    return (dsu.size(1) == N ? ans : -1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("threesum.in", "r", stdin);
    //freopen("threesum.out", "w", stdout);
    int n,m;
    cin>>n>>m;
    vector<pair<long long,pair<int,int>>> edges(n);
    for(int i = 0; i<m; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        a--;
        b--;
        edges.push_back({c,{a,b}});
    }
    long long ans = kruskal(n,edges);
    if(ans == -1)
    {
        cout<<"IMPOSSIBLE";
        return 0;
    }
    cout<<ans;
}