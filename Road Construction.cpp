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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    DSU dsu(n);
    int maxy = 1;
    int connct = n;
    for(int i = 0; i<m; i++)
    {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        if(dsu.unite(a,b))
        {
            maxy= max(maxy, dsu.size(a));
            connct--;
        }
        cout<<connct<<" "<<maxy<<endl;
    }
}