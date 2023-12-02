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
    freopen("cowdance.in","r",stdin);
    freopen("cowdance.out","w",stdout);
    int n,tmax;
    cin>>n>>tmax;
    vector<int> dance;
    for(int i = 0; i<n; i++)
    {
        int num;
        cin>>num;
        dance.push_back(num);
    }
    int l = 1;
    int r = n+1;
    while(l<r)
    {
        int medium = (l+r+1)/2;
        priority_queue<int,vector<int>,greater<int>> current;
        int time=0;
        int curr = medium;
        for(int i = 0; i<medium; i++)
        {
            current.push(dance[i]);
        }
        while(!current.empty())
        {
            int leave = current.top();
            current.pop();
            time = max(time,leave);

            if(curr<n)
            {
                current.push(dance[curr]+leave);
                curr++;
            }
        }
        if(time<=tmax)
            r = medium;
        else
            l = medium+1;
    }
    cout<<l;
}