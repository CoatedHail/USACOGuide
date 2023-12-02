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
    int cost;
    int i;
    int j;
};
bool cmp(Edge a, Edge b)
{
    return a.cost<b.cost;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("fencedin.in", "r", stdin);
    freopen("fencedin.out", "w", stdout);
    int A,B,n,m;
    cin>>A>>B>>n>>m;
    vector<int> vx(n + 1), vy(m + 1);
    for(int i = 1; i<=n; i++)
    {
        cin>>vx[i];
    }
    for(int i = 1; i<=m; i++)
        cin>>vy[i];
    vx.push_back(A);
    vy.push_back(B);
    sort(vx.begin(),vx.end());
    sort(vy.begin(),vy.end());
    n+=2;
    m+=2;
    vector<Edge> edges;
    int curr =0; int row = 1;
    while(row<m)
    {
        for(int i = 0; i<n-2; i++)
        {
            edges.push_back({vy[row]-vy[row-1],curr,curr+1});
            curr++;
        }
        curr++;
        row++;
    }
    curr = n - 1;
    int col = 1;
    while (col < n) {
        int init = curr;
        for (int i = 0; i < m - 2; i++) {
            edges.push_back({vx[col] - vx[col - 1], curr - (n - 1), curr});
            curr += (n - 1);
        }
        curr = init + 1;
        col++;
    }
    DSU dsu((n+2)*(m*2));
    sort(edges.begin(),edges.end(),cmp);
    long long ans = 0;
    for(Edge e: edges)
    {
        if (dsu.unite(e.i, e.j)) { ans += e.cost; }
    }
    cout<<ans;
}
