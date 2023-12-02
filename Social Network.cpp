#include <iostream>
#include <math.h>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <cstdio>

using namespace std;

struct DSU {
    vector<int> to;
    vector<int> val;
    int safeEdges = 0;
    multiset<int> topVals;
    multiset<int> tempVals;

    DSU(int n) {
        to.resize(n);
        val.resize(n, 1);
        for (int i = 0; i < n; ++i) {
            to[i] = i;
            tempVals.insert(val[i]);
        }
    }

    int f(int v) {
        if (v == to[v])
            return v;
        return to[v] = f(to[v]);
    }

    bool check(multiset<int>& st, int val) {
        auto it = st.lower_bound(val);
        if (it == st.end())
            return false;
        return (*it == val);
    }
    long long sum = 0;
    void merge(int x, int y) {
        x = f(x);
        y = f(y);
        if (x == y) {
            ++safeEdges;
            return;
        }
        if (check(tempVals, val[x]))
            tempVals.erase(tempVals.lower_bound(val[x]));
        else {
            sum -= val[x];
            topVals.erase(topVals.lower_bound(val[x]));
        }
        if (check(tempVals, val[y]))
            tempVals.erase(tempVals.lower_bound(val[y]));
        else {
            sum -= val[y];
            topVals.erase(topVals.lower_bound(val[y]));
        }

        to[y] = x;
        val[x] = val[x] + val[y];

        tempVals.insert(val[x]);
    }



    int getAnswer() {
        while (tempVals.size() && topVals.size() < safeEdges + 1) {
            sum += (*--tempVals.end());
            topVals.insert(*--tempVals.end());
            tempVals.erase(--tempVals.end());
        }

        while (tempVals.size() && (*topVals.begin()) < (*--tempVals.end())) {
            sum -= *topVals.begin();

            int temp = *topVals.begin();
            topVals.erase(topVals.begin());
            tempVals.insert(temp);

            sum += *--tempVals.end();
            topVals.insert(*--tempVals.end());

            tempVals.erase(*--tempVals.end());
        }

        return sum - 1;
    }
} ;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,d;
    cin>>n>>d;
    DSU dsu(n+1);
    for(int i = 0; i<d; i++)
    {
        int a,b;
        cin>>a>>b;
        dsu.merge(a,b);
        cout<<dsu.getAnswer()<<endl;
    }
}
