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

struct DSU {
    long long int *parent;
    long long int *rank;


    DSU(int n) {
        parent = new long long[n];
        rank = new long long[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }

    }

    int find(int i) {
        if (parent[i] == i)
            return i;

        return parent[i] = find(parent[i]);
    }
    void unite(int x, int y)
    {
        int s1 = find(x);
        int s2 = find(y);
        if(s1==s2)
            return;
        if (rank[s1] < rank[s2]) {
            parent[s1] = s2;
            rank[s2] += rank[s1];
        }
        else {
            parent[s2] = s1;
            rank[s1] += rank[s2];
        }

    }
};

struct wormhole{
    int a;
    int b;
    int width;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("wormsort.in", "r", stdin);
    //freopen("wormsort.out", "w", stdout);
    int n,m;
    cin>>n>>m;
    vector<wormhole> worms;
    vector<int> places;
    for(int i = 0; i<n; i++)
    {
        int num;
        cin>>num;
        places.push_back(num-1);
    }
    int maximum=-1;
    for(int i = 0; i<m; i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        wormhole z;
        z.a = x-1;
        z.b = y-1;
        z. width = w;
        worms.push_back(z);
        maximum = max(maximum,w);
    }
    int l = 0;
    int h = maximum+1;
    int valid = 0;
    while(l<= h)
    {
        int mid = (l+h)/2;
        DSU dsu(n);
        for(wormhole w : worms) {
            if (w.width >= mid) {
                dsu.unite(w.a, w.b);
            }
        }
        bool sortable = true;
        for(int i = 0; i<n; i++)
        {
            if(dsu.find(i)!=dsu.find(places[i]))
            {
                sortable = false;
                break;
            }
        }
        if(sortable == true)
        {
            valid = mid;
            l = mid+1;
        }
        else
            h = mid-1;
    }
    if(valid == maximum+1)
        cout<<-1;
    else
        cout<<valid;
}