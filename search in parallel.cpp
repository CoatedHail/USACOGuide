#include <iostream>
#include <math.h>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cstdio>

using namespace std;

const int mod = 1e9+7;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        long long n,s1,s2;
        cin>>n>>s1>>s2;
        int fi=1,se=1;
        vector<int> a,b;
        vector<pair<int,int>> asks;
        for(int i =0 ; i<n; i++)
        {
            int num;
            cin>>num;
            asks.push_back(make_pair(num,i+1));
        }
        sort(asks.begin(),asks.end(),greater<pair<int,int>>());
        for(int i = 0; i<n; i++)
        {
            if(s1*fi>=s2*se)
            {
                b.push_back(asks[i].second);
                se++;
            }
            else
            {
                a.push_back(asks[i].second);
                fi++;
            }
        }
        cout<<a.size()<<" ";
        for(auto x: a)
            cout<<x<<" ";
        cout<<endl;
        cout<<b.size()<<" ";
        for(auto x: b)
            cout<<x<<" ";
        cout<<endl;
    }
}
