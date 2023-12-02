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
    freopen("reststops.in","r",stdin);
    freopen("reststops.out","w",stdout);
    int l,n,rf,rb;
    cin>>l>>n>>rf>>rb;
    vector<int> pos,taste;
    for(int i = 0; i<n; i++)
    {
        int a,b;
        cin>>a>>b;
        pos.push_back(a);
        taste.push_back(b);
    }
    vector<bool> good(l,false);
    int max = 0;
    for(int i = n-1; i>=0; i--)
    {
        if(taste[i]>max)
        {
            good[i]=true;
            max = taste[i];

        }
    }
    long long prev,ans;
    prev = ans = 0;
    for(int i = 0; i<n; i++)
    {
        if(good[i]==true)
        {
            long long dist = pos[i]-prev;
            long long ftime = rf*dist;
            long long btime = rb*dist;
            ans+=(ftime-btime)*taste[i];
            prev = pos[i];
        }
    }
    cout<<ans;
}