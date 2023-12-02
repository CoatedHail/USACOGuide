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
    vector<vector<int>> seq;
    for(int i = 0; i<n; i++)
    {
        int a;
        cin>>a;
        int l = 0; int r = seq.size();
        while(l<r)
        {
            int medium = (l+r)/2;
            if(seq[medium].back()<a)
                r=medium;
            else
                l=medium+1;
        }
        vector<int> v;
        v.push_back(a);
        if(l==seq.size())
            seq.push_back(v);
        else
            seq[l].push_back(a);
    }
    for(int i = 0; i<seq.size(); i++)
    {
        for(int j :seq[i])
            cout<<j<<" ";
        cout<<endl;
    }
}