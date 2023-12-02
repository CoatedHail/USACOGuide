#include <iostream>
#include <math.h>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cstdio>

using namespace std;

int n,m,c;
vector<int> arrive;
bool valid(int k) {
    int bus = 0;
    int curr = 0;
    int earl = 0;
    while (curr < n) {
        if (curr == earl)
            bus++;
        if (arrive[curr] - arrive[earl] > k) {
            earl = curr;
        } else if (curr - earl + 1 == c) {
            earl = curr+1;
            curr++;
        } else
            curr++;
    }
    return bus<=m;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("convention.in","r",stdin);
    freopen("convention.out","w",stdout);
    cin>>n>>m>>c;
    for(int i = 0; i<n; i++)
    {
        int num;
        cin>>num;
        arrive.push_back(num);
    }
    sort(arrive.begin(),arrive.end());
    int l = 0;
    int r= arrive[n-1]-arrive[0];
    while(l<r)
    {
        int mid = (l+r)/2;
        if(valid(mid))
        {
            r = mid;
        }
        else
            l = mid+1;
    }
    cout<<r;
}