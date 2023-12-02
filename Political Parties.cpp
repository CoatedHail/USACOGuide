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

vector<long long> v;
vector<long long> intra;
vector<long long> ontra;
set<pair<long long,long long>> s;
vector<vector<long long>> argued;
void adjust(int a)
{
    v[a]*=-1;
    long long d = intra[a];
    intra[a]=ontra[a];
    ontra[a]=d;
    for(auto x: argued[a])
    {
        if(v[x]==v[a])
        {
            ontra[x]--;
            intra[x]++;
        }
        else
        {
            intra[x]--;
            ontra[x]++;
        }
        if(intra[x]>=3){
            adjust(x);
        }

    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    cin>>n;
    v.resize(n+1,1);
    intra.resize(n+1,0);
    ontra.resize(n+1,0);
    argued.resize(n+1);
    for(int i = 0; i<5; i++)
    {
        long long k;
        cin>>k;
        for(int j = 0; j<k; j++)
        {
            long long a,b;
            cin>>a>>b;
            if(s.count({a,b})>0||s.count({b,a})>0)
                continue;
            s.insert({a,b});
            argued[a].push_back(b);
            argued[b].push_back(a);
            if(v[a]==v[b])
            {
                intra[a]++;
                intra[b]++;
            }
            else
            {
                ontra[a]++;
                ontra[b]++;
            }
            if(intra[a]>=3)
            {
                adjust(a);
            }
            if(intra[b]>=3)
            {
                adjust(b);
            }
        }
    }
    for(int i = 1; i<=n; i++)
    {
        if(v[i]==1)
            cout<<"A";
        else
            cout<<"B";
    }
}