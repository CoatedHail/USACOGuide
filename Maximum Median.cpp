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
    sort(v.begin(),v.end());
    int curr = v[n/2];
    int l=curr;
    int r = v[n-1]+k;
    while(l<r)
    {
        int medium = (l+r+1)/2;
        int cost = 0;
        for(int i = n/2; i<n; i++)
        {
            cost+=(medium-v[i]);
        }
        if(cost<=k)
        {
            l = medium;
        }
        else
            r=medium-1;
    }
    cout<<l;
}