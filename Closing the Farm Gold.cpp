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
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
    int n,m;
    cin>>n>>m;
    DSU dsu(n);
    vector<vector<int>> adj(n);
    for(int i = 0; i<m; i++)
    {
        int a,b;
        cin>>a>>b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<bool> closed(n);
    vector<int> rev(n);
    for(int i = 0; i<n; i++)
    {
        cin>>rev[i];
        rev[i]--;
    }
    reverse(rev.begin(),rev.end());
    closed[rev[0]]=true;
    vector<string> ans;
    ans.push_back("YES");
    int cc = 1;
    for(int i = 1; i<n; i++)
    {
        cc++;
        closed[rev[i]]=true;
        for(int j : adj[rev[i]])
        {
            if(closed[j])
                if(dsu.unite(j,rev[i]))
                    cc--;
        }
        if(cc==1)
            ans.push_back("YES");
        else
            ans.push_back("NO");
    }
    reverse(ans.begin(),ans.end());
    for(auto x:ans)
        cout<<x<<endl;
}