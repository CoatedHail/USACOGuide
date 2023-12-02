#include <iostream>
#include <math.h>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cstdio>

using namespace std;

const int mod = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i =0; i<n; i++)
        cin>>v[i];
    vector<int> with_h(n+1);
    for (int i = 0; i < n; ++i) with_h[v[i]] = i;
    long long ans = 0;
    set<int> present;
    for(int curr = n; curr>0; curr--)
    {
        auto it = present.insert(with_h[curr]).first;
        if(next(it)!=end(present)) ans+=*next(it)-*it+1;
    }
    reverse(v.begin(),v.end());
    for (int i = 0; i < n; ++i) with_h[v[i]] = i;
    set<int> present2;
    for(int curr = n; curr>0; curr--)
    {
        auto it = present2.insert(with_h[curr]).first;
        if(next(it)!=end(present2)) ans+=*next(it)-*it+1;
    }
    cout<<ans;
}
