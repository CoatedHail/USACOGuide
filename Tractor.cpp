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



struct Cell {
    int i, j;
};
struct Edge {
    Cell from, to;
    int cost;
};
bool cmp(Edge a, Edge b)
{
    return a.cost<b.cost;
}
vector<int> parent(250000);
vector<int> compsize(250000);
vector<Edge> edges;
int n;
void init() {
    for (int i = 0; i < n * n; i++) {
        parent[i] = i;
        compsize[i] = 1;
    }
}

int find(int a) {
    if (a == parent[a]) { return a; }
    return parent[a] = find(parent[a]);
}

bool unite(int a, int b) {
    int root_a = find(a), root_b = find(b);
    if (root_a == root_b) { return false; }
    if (compsize[root_a] > compsize[root_b]) { swap(root_a, root_b); }
    parent[root_a] = root_b;
    compsize[root_b] += compsize[root_a];
    return compsize[root_b] >= (n * n + 1) / 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("tractor.in", "r", stdin);
    freopen("tractor.out", "w", stdout);
    cin>>n;
    vector<vector<int>> grid(n,vector<int>(n));
    for(int i =0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            cin>>grid[i][j];
        }
    }
    init();
    int di[4]={-1,0,1,0};
    int dj[4]={0,1,0,-1};
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++) {
            for(int d = 0; d<4; d++)
            {
                Cell to;
                to.i = i+di[d];
                to.j = j+dj[d];
                if (to.i >= 0 && to.i < n && to.j >= 0 && to.j < n &&
                    grid[i][j] >= grid[to.i][to.j]) {
                    edges.push_back(
                            {{i, j}, to, grid[i][j] - grid[to.i][to.j]});
                }
            }
        }
    }
    sort(edges.begin(),edges.end(),cmp);
    for(Edge e:edges)
    {
        if(unite(e.from.i * n + e.from.j, e.to.i * n + e.to.j))
        {
            cout<<e.cost<<endl;
            return 0;
        }
    }
}