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

vector<int> lefts,rights;
bool cmp(const long long x, const long long y) {
    if(lefts[x]==lefts[y])
    {
        return rights[x]>rights[y];
    }
    return lefts[x]<lefts[y];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("mountains.in", "r", stdin);
    freopen("mountains.out", "w", stdout);
    int n;
    cin>>n;
    vector<int> v;
    for(int i = 0; i<n; i++)
    {
        int a,b;
        cin>>a>>b;
        lefts.push_back(a-b);
        rights.push_back(a+b);
        v.push_back(i);
    }
    sort(v.begin(),v.end(), cmp);
    int max = -1;
    int ans = 0;
    for(int i=0; i<n;i++)
    {
        if(rights[v[i]] > max)
        {
            ans++;
            max = rights[v[i]];
        }
    }
    cout<<ans;

}
