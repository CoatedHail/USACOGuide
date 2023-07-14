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

vector<pair<int,int>> v;
bool cmp(pair<int,int> a, pair<int,int> b)
{
    if(a.first==b.first) return a.second<b.second;
    return a.first<b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    int n;
    int ans = 0;

    cin>>n;
    for(int i = 0; i<n; i++)
    {
        int num;
        cin>>num;
        v.push_back(make_pair(num,i));
    }
    sort(v.begin(),v.end(), cmp);
    for(int i = 0; i<n; i++)
    {
        ans = max(ans, v[i].second-i);
    }
    cout<<ans+1;
}
