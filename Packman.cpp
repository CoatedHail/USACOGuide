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

bool works(vector<int>& packman, deque<int> food, int time)
{
    for(int p : packman)
    {
        vector<int> edible;
        while(!food.empty()&&food[0]<p)
        {
            edible.push_back(food[0]);
            food.pop_front();
        }
        if(edible.empty())
        {
            while(!food.empty()&&food[0]-p<=time)
            {
                food.pop_front();
            }
        }
        else
        {
            if(p-edible[0]>time)
            {
                return false;
            }
            int left = p-edible[0];
            int right = time-2*left;
            int leftfirst = -1;
            while(leftfirst+1<food.size()&&food[leftfirst+1]-p<=right)
                leftfirst++;
            right=time-left;
            int rightfirst=-1;
            while(rightfirst+1<food.size()&&(food[rightfirst+1]-p)*2<=right)
            {
                rightfirst++;
            }
            for(int i = 0; i<max(rightfirst,leftfirst)+1; i++)
            {
                food.pop_front();
            }
        }
        if(food.empty())
            return true;
    }
    return food.empty();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> packman;
    deque<int> food;
    for(int i = 0; i<s.size(); i++)
    {
        if(s[i]=='P')
            packman.push_back(i);
        else if(s[i]=='*')
            food.push_back(i);
    }
    int l = 0;
    int r = s.size()*2;
    int valid = -1;
    while(l<=r)
    {
        int mid = (l+r)/2;
        if(works(packman,food,mid))
        {
            valid = mid;
            r = mid-1;
        }
        else
            l=mid+1;
    }
    cout<<valid;
}