#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"
#include "set"
#include "stack"
#include "map"
#include "limits.h"
#include "cstdio"
#include "math.h"
#include <iomanip>
#include <numeric>
using namespace std;

int dist(pair<int,int> &p1,pair<int,int>& p2)
{
    int dx = p1.first-p2.first;
    int dy = p1.second-p2.second;
    return dx*dx+dy*dy;
}

bool possible(int power, vector<pair<int,int>>& cows)
{
    int start = 0;
    queue<int> frontier;
    frontier.push(start);
    vector<bool> reached(cows.size());
    reached[start]=true;
    while(!frontier.empty())
    {
        int top = frontier.front();
        frontier.pop();
        for(int i = 0; i<cows.size(); i++)
        {
            if(!reached[i]&&dist(cows[top],cows[i])<=power)
            {
                frontier.push(i);
                reached[i]=true;
            }
        }
    }
    for(int i = 0; i<cows.size(); i++)
    {
        if(reached[i]==false)
            return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("moocast.in", "r", stdin);
    //freopen("moocast.out", "w", stdout);
    int n;
    cin>>n;
    vector<pair<int,int>> cows(n);
    for(int i = 0; i<n; i++)
    {
        int x,y;
        cin>>x>>y;
        cows.push_back(make_pair(x,y));
    }
    int l = 0;
    int h = INT_MAX;
    int valid=0;
    while(l<=h)
    {
        int mid =  (h+l)/2;
        if(possible(mid,cows))
        {
            valid = mid;
            h = mid-1;
        }
        else
            l = mid+1;
    }
    cout<<valid;
}