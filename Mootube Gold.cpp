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
    DSU(int N) { e = vector<int>(N, -1); }

    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

    bool same_set(int a, int b) { return get(a) == get(b); }

    int size(int x) { return -e[get(x)]; }

    bool unite(int x, int y) {
        x = get(x), y = get(y);
        if (x == y) return false;
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y];
        e[y] = x;
        return true;
    }
};

bool cmp(const pair<int, pair<int, int>> &a,
         const pair<int, pair<int, int>> &b) {
    return a.second.second > b.second.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    int n,q;
    cin>>n>>q;
    vector<pair<int,pair<int,int>>> edges(n-1);
    for(int i = 0; i<n-1; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        u--;
        v--;
        edges[i] = make_pair(w,(make_pair(u,v)));
    }
    vector<pair<int,pair<int,int>>> queries(q);
    for(int i = 0; i<q; i++)
    {
        int a,b;
        cin>>b>>a;
        a--;
        queries[i]=make_pair(i,make_pair(a,b));
    }
    sort(queries.begin(), queries.end(), cmp);
    sort(edges.begin(), edges.end(), greater<pair<int, pair<int, int>>>());
    DSU dsu(n);
    vector<int> sol(q);
    int index = 0;
    for(auto query: queries)
    {
        int v = query.second.first;
        int curk = query.second.second;
        while (index < (int)edges.size() && edges[index].first >= curk) {
            dsu.unite(edges[index].second.first, edges[index].second.second);
            index++;
        }
        sol[query.first] = dsu.size(v) - 1;
    }
    for(auto x:sol)
        cout<<x<<endl;
}