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
struct Edge {
    int from, to, weight;
};
bool cmp(Edge a, Edge b) {
    return a.weight > b.weight;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("superbull.in", "r", stdin);
    freopen("superbull.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> ids(n);
    for (int i = 0; i < n; i++) { cin >> ids[i]; }
    vector<Edge> edges;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            edges.push_back({i, j, ids[i] ^ ids[j]});
        }
    }
    DSU dsu(n);
    sort(edges.begin(),edges.end(),cmp);
    int eli = 0;
    long long ans = 0;
    for(Edge e: edges)
    {
        if(dsu.unite(e.from,e.to))
        {
            eli++;
            ans+=e.weight;
            if(eli == n-1)
            {
                cout<<ans<<endl;
                return 0;
            }
        }
    }
}
