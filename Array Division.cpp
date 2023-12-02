
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
    vector<long long> v;
    long long max = 0;
    for(int i =0; i<n; i++)
    {
        int num;
        cin>>num;
        v.push_back(num);
        max+=num;
    }
    //sort(v.begin(),v.end());
    long long l = 0; long long r = max;
    while(l<r) {
        long long medium = (l+r)/2;
        int curr=0;
        bool works = false;
        for (int i = 0; i < k; i++) {
            long long sum = 0;
            while(true) {
                if (sum + v[curr] > medium||curr==n) {
                    break;
                }
                sum += v[curr];
                curr++;
            }
            if(curr==n)
            {
                works = true;
                break;
            }
        }
        if(works == true)
        {
            r = medium;
        }
        else
            l=medium+1;
    }
    cout<<r;
}