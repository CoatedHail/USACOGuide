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
        long long n,m,z,k,y;
        cin>>n>>m>>z;
        vector<vector<long long>> fis,sec;
        long long p = z;
        while(p%m==0)
            p/=m;
        fis.push_back({p,z/p});
        for(int i = 1; i<n; i++)
        {
            long long x;
            cin>>x;
            p = x;
            while(x%m==0)
                x/=m;
            int l = fis.size()-1;
            if(fis[l][0]==x)
                fis[l][1]+=p/x;
            else
                fis.push_back({x,p/x});
        }
        cin>>k>>y;
        p = y;
        while(y%m==0)
            y/=m;
        sec.push_back({y,p/y});
        for(int i = 1; i<k; i++)
        {
            long long x;
            cin>>x;
            p = x;
            while(x%m== 0)
                x/=m;
            int l = sec.size()-1;
            if(sec[l][0]==x)
                sec[l][1]+=p/x;
            else
                sec.push_back({x,p/x});
        }
        if(fis==sec)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}
