#include <iostream>
#include <math.h>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <set>
#include <unordered_map>
#include <iomanip>
#include <cstdio>

using namespace std;

const int mod = 1e9+7;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long q;
    cin>>q;
    while(q--)
    {
        long long n,m,d;
        cin>>n>>m>>d;
        vector<long long> v(n);
        for(int i =0; i<n; i++)
            cin>>v[i];
        long long ans = 0;
        set<pair<long long,long long>> s;
        long long sum = 0;
        for(int i = 0; i<n; i++)
        {
            long long cur = sum+v[i]-d*(i+1);
            ans = max(ans,cur);
            if(v[i]>0)
            {
                s.insert({v[i],i});
                sum+=v[i];
                if(s.size()>=m)
                {
                    sum-=(s.begin()->first);
                    s.erase(s.begin());
                }
            }
        }
        cout<<ans<<endl;
    }
}
