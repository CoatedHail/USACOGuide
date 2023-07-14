
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

struct boot{
    int index;
    int height;
    int length;
};
bool cmp(boot a, boot b)
{
    return a.height>b.height;
}
bool cmp2(int a, int b)
{
    return a>b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("snowboots.in", "r", stdin);
    freopen("snowboots.out", "w", stdout);
    int n,m;
    cin>>n>>m;
    vector<int> v;
    vector<boot> boots;
    for(int i = 0; i<n; i++)
    {
        int num;
        cin>>num;
        v.push_back(num);
    }
    for(int i = 0; i<m; ++i)
    {
        boot b;
        b.index = i;
        cin>>b.height>>b.length;
        boots.push_back(b);
    }
    sort(boots.begin(),boots.end(),cmp);
    vector<int> tiles;
    for(int i = 1; i<n-1; i++)
    {
        tiles.push_back(i);
    }
    sort(tiles.begin(), tiles.end(),
         [&](int a, int b) { return v[a] > v[b]; });
    set<int> valid;
    for (int i = 0; i < n; i++) { valid.insert(i); }
    int minstep=1;
    int deep=0;
    vector<bool> reach(m);
    for(const boot& b : boots)
    {
        while(deep<tiles.size()&&v[tiles[deep]]>b.height)
        {
            auto removed = valid.find(tiles[deep]);
            minstep = max(minstep, *next(removed)-*prev(removed));
            valid.erase(removed);
            deep++;
        }
        reach[b.index]=b.length>=minstep;
    }
    for(bool b: reach)
        cout<<b<<endl;
}
