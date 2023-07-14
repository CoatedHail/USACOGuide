
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


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, x;
    cin>>n>>x;
    vector<pair<long long, long long>> v;
    for(int i = 0; i<n; i++)
    {
        long long num;
        cin>>num;
        v.push_back(make_pair(num,i+1));
    }
    sort(v.begin(),v.end());

    for(int i = 0; i<n; i++)
    {
        long long left = 0, right = n-1;
        if(left == i)
            left++;
        if(right== i)
            right--;
        while(left<right)
        {
            if(v[left].first+v[right].first==x-v[i].first)
            {
                cout<<v[i].second<<" "<<v[left].second<<" "<<v[right].second;
                return 0;
            }
            else if(v[left].first+v[right].first<x-v[i].first)
            {
                left++;
                if(left==i)
                    left++;
            }
            else
            {
                right--;
                if(right==i)
                    right--;
            }
        }
    }
    cout<<"IMPOSSIBLE";
}
