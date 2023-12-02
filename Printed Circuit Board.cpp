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


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<pair<int,int>> a;
    int lis = 0;
    set<int> s;
    for(int i = 0; i<n; i++)
    {
        int x,y;
        cin>>x>>y;
        a.push_back({x,y});
    }
    sort(a.begin(),a.end(),greater<pair<int,int>>());
    for(int i =0 ; i<n; i++)
    {
        if(s.upper_bound(a[i].second)==s.end()) lis++;
        else s.erase(s.upper_bound(a[i].second));
        s.insert(a[i].second);
    }
    cout<<lis;
}