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
    int n;
    cin>>n;
    vector<double> location,speed;
    double maxy = 0;
    for(int i = 0; i<n; i++)
    {
        double num;
        cin>>num;
        location.push_back(num);
    }
    for(int i = 0; i<n; i++)
    {
        double num;
        cin>>num;
        speed.push_back(num);
    }
    for(int i = 1; i<n; i++)
    {
        maxy=max(maxy, abs(location[i]-location[0])/speed[i]);
    }
    double l = 0.0;
    double r=maxy;
    while(l<r-0.0000001)
    {
        double medium = (l+r)/2;
        double currb,curre;
        currb=location[0]-speed[0]*medium;
        curre=location[0]+speed[0]*medium;
        bool works = true;
        for(int i = 1; i<n; i++)
        {
            double newb,newe;
            newb = location[i]-speed[i]*medium;
            newe = location[i]+speed[i]*medium;
            if(newb>curre||newe<currb)
            {
                works = false;
                break;
            }
            currb = max(currb,newb);
            curre = min(curre,newe);
        }
        if(works == false)
        {
            l = medium;
        }
        else
            r = medium;
    }
    cout<<r;
}