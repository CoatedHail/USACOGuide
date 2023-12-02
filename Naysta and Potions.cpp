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

long long n,k;
vector<vector<long long>> mix;
vector<long long> c;
vector<bool> vis;
long long dp(long long curr)
{
    if(vis[curr])
        return c[curr];
    if(mix[curr].size()==0)
    {
        vis[curr]=true;
        return c[curr];
    }
    long long craft = 0;
    for(auto x: mix[curr])
        craft+=dp(x);
    c[curr]=min(c[curr],craft);
    vis[curr]=true;
    return c[curr];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t;
    cin>>t;
    while(t--) {
        cin>>n>>k;
        mix.clear();
        c.clear();
        vis.clear();
        mix.resize(n);
        c.resize(n);
        vis.resize(n,false);
        for(long long i =0; i<n; i++)
            cin>>c[i];
        for(long long i = 0; i<k; i++) {
            long long num;
            cin>>num;
            c[num-1]=0;
        }

        for(long long i = 0; i<n; i++)
        {
            long long num;
            cin>>num;
            for(long long j = 0; j<num; j++)
            {
                long long x;
                cin>>x;
                x--;
                mix[i].push_back(x);
            }
        }
        for(long long i = 0; i<n; i++)
            cout<<dp(i)<<" ";
        cout<<endl;
    }
}