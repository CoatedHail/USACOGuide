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

struct location
{
    long long x,y,time;
};
bool cmp(location a,location b)
{
    return a.time<b.time;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long g,n;
    cin>>g>>n;
    vector<location> grazings,cows;
    for(int i =0; i<g; i++)
    {
        long long a,b,c;
        cin>>a>>b>>c;
        grazings.push_back({a,b,c});
    }
    sort(grazings.begin(),grazings.end(),cmp);
    for(int i =0; i<n; i++)
    {
        long long a,b,c;
        cin>>a>>b>>c;
        cows.push_back({a,b,c});
    }
    sort(cows.begin(),cows.end(),cmp);
    long long ans = 0;
    for(int i =0; i<n; i++)
    {
        long long a=cows[i].x;
        long long b = cows[i].y;
        long long t = cows[i].time;
        long long l = 0;
        long long r = g-1;
        long long upper=g-1;
        while(l<=r)
        {
            long long mid = (l+r+1)/2;
            if(grazings[mid].time<=t)
            {
                l = mid+1;

            }
            else
            {
                r = mid-1;
                upper = mid;
            }
        }
        if(upper == 0)
        {
            if(abs(grazings[0].time-t)*abs(grazings[0].time-t)>=(abs(grazings[0].x-a)*abs(grazings[0].x-a)+abs(grazings[0].y-b)*abs(grazings[0].y-b)))
                ans++;
        }
        else
        {
            if(abs(grazings[upper].time-t)*abs(grazings[upper].time-t)>=(abs(grazings[upper].x-a)*abs(grazings[upper].x-a)+abs(grazings[upper].y-b)*abs(grazings[upper].y-b))&&
               abs(grazings[upper-1].time-t)*abs(grazings[upper-1].time-t)>=(abs(grazings[upper-1].x-a)*abs(grazings[upper-1].x-a)+abs(grazings[upper-1].y-b)*abs(grazings[upper-1].y-b)))
                ans++;

        }
    }
    cout<<n-ans;
}