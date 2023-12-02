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
    int n,k;
    cin>>n>>k;
    vector<int> v;
    for(int i = 0; i<n; i++)
    {
        int num;
        cin>>num;
        v.push_back(num);
    }
    int l = 0;
    int r= n;
    while(l<r)
    {
        int medium = (l+r)/2;
        vector<int> f(n);
        for(int i = 0; i<n; i++)
        {
            if(v[i]>=medium)
                f[i]=1;
            else
                f[i]=-1;
            if(i>0)
                f[i]+=f[i-1];
        }
        int mn = 0;
        int diff = 0;
        for(int i = k-1; i<n; i++)
        {
            mn = min(mn, f[i-k]);
            diff = max(diff,f[i]-mn);
        }
        if(diff>0)
        {
            l=medium;
        }
        else
            r=medium-1;
    }
    cout<<l;

}