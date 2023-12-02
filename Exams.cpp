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



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<pair<int,int>> v;
    for(int i = 0; i<n; i++){
        int a,b;
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }
    int curr = 0;
    sort(v.begin(),v.end());
    for(int i = 0; i<n; i++)
    {
        if(v[i].second >= curr)
            curr=v[i].second;
        else
            curr = v[i].first;
    }
    cout<<curr;
}
