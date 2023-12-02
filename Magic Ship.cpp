
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

bool check(pair<long long, long long> start, pair<long long, long long> end, string s, long long time) {
    long long windx = 0;
    long long windy = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'U')
            windy++;
        else if (s[i] == 'D')
            windy--;
        else if (s[i] == 'L') {
            windx--;
        } else
            windx++;
    }
    windx *= time / s.size();
    windy *= time / s.size();
    long long remainder = time % s.size();
    for (int i = 0; i < remainder; i++) {
        if (s[i] == 'U')
            windy++;
        else if (s[i] == 'D')
            windy--;
        else if (s[i] == 'L') {
            windx--;
        } else
            windx++;
    }
    start.first+=windx;
    start.second+=windy;
    return abs(start.first-end.first)+abs(start.second-end.second)<=time;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pair<long long, long long> begin,end;
    cin>>begin.first>>begin.second;
    cin>>end.first>>end.second;
    int n;
    cin>>n;
    string s;
    cin>>s;
    int l = 0;
    int r = INT_MAX;
    long long ans = -1;
    while(l<r)
    {
        int mid = (l+r)/2;
        if(check(begin,end,s,mid))
        {
            ans=mid;
            r=mid-1;
        }
        else
            l=mid+1;
    }
    cout<<ans;
}