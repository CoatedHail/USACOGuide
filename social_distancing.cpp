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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("socdist.in","r",stdin);
    freopen("socdist.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<pair<long long,long long>> v;
    for(int i = 0; i<m; i++)
    {
        long long a,b;
        cin>>a>>b;
        v.push_back(make_pair(a,b));

    }
    sort(v.begin(),v.end());
    int l = 0; int r = v[m-1].second-v[0].first+1;
    while(l<r)
    {
        long long mid = (l+r)/2;
        long long curr = 0;
        long long count = 1;
        long long interval = 0;
        while(curr+mid<=v[m-1].second)
        {
            while(curr+mid>v[interval].second)
                interval++;
            curr = max(curr+mid, v[interval].first);
            count++;
            if(count == n)
                break;
        }
        if(count <n)
        {
            r = mid-1;
        }
        else
            l=mid;
    }
    cout<<l;
}