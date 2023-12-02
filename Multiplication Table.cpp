
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
    long long n;
    cin>>n;
    long long l,r,mid,leq;
    l=1,r=n*n;
    while(l<r)
    {
        mid=(l+r)/2;
        leq=0;
        for(int i = 1; i<=n; i++)
        {
            leq+=min(n,mid/i);
        }
        if(leq>=(n*n+1)/2)
            r = mid;
        else
            l=mid+1;
    }
    cout<<r;
}