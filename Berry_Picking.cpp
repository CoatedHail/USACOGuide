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

int mod;

bool cmp(int a,int b)
{
    return (a%mod)>(b%mod);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("berries.in","r",stdin);
    freopen("berries.out","w",stdout);
    int n,k;
    cin>>n>>k;
    vector<int> berry;
    int M=0;
    for(int i = 0;i<n; i++)
    {
        int num;
        cin>>num;
        berry.push_back(num);
        M = max(M,num);
    }
    int best=0;
    for(int i = 1; i<M; i++)
    {
        int full = 0;
        for(int j = 0; j<n; j++)
        {
            full+=berry[j]/i;
        }
        mod = i;
        if(full<(k/2))
            break;
        if(full>=k)
        {
            best = max(best, i*(k/2));
            continue;
        }
        sort(berry.begin(),berry.end(),cmp);
        int curr = i*(full-(k/2));
        for(int j = 0; j<n&&j+full<k;j++)
        {
            curr+=berry[j]%i;
        }
        best = max(best,curr);
    }
    cout<<best;
}