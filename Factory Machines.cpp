
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
    long long n,t;
    cin>>n>>t;
    vector<long long> nece;
    long long biggest = 0;
    for(int i = 0; i<n; i++)
    {
        long long num;
        cin>>num;
        nece.push_back(num);
        biggest = max(biggest,num);
    }
    long long l = 0;
    long long r = biggest*t;
    while(l<r)
    {
        long long medium = (l+r)/2;
        int curr =0;
        int count = 0;
        while(true)
        {
            if(nece[curr]>medium||curr==n)
                break;
            count+=medium/nece[curr];
            curr++;
        }
        if(count>=t)
        {
            r=medium;
        }
        else
            l=medium+1;


    }
    cout<<r;
}