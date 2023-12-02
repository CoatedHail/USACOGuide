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
    freopen("angry.in","r",stdin);
    freopen("angry.out","w",stdout);
    int n,k;
    cin>>n>>k;
    vector<int> v;
    for(int i = 0; i<n; i++)
    {
        int num;
        cin>>num;
        v.push_back(num);
    }
    sort(v.begin(),v.end());
    int l =0;
    int r=(v[n-1]-v[0]);

    while(l<r)
    {
        int mid = (l+r)/2;
        int lastexplosion=-1;
        int curr=0;
        int count = 0;
        while(curr<n) {
            if (v[curr] > lastexplosion) {
                lastexplosion = v[curr] + 2*mid;
                count++;
            }
            curr++;
        }
        if(count<=k)
        {
            r=mid;
        }
        else
            l=mid+1;
    }
    cout<<r;
}