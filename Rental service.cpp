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

bool cmp(const long long x, const long long y) { return x > y; }

bool cmp2(const pair<long long, long long> &x, const pair<long long, long long> &y) { return x.first > y.first; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("rental.in", "r", stdin);
    freopen("rental.out", "w", stdout);
    int n,m,r;
    cin>>n>>m>>r;
    vector<long long> sell(n+1,0),rent(r+1,0),milk,rprice;
    vector<pair<long long,long long>> sprice;
    for(int i = 0; i<n; i++)
    {
        int num;
        cin>>num;
        milk.push_back(num);
    }
    for(int i = 0; i<m; i++)
    {
        long long a,b;
        cin>>a>>b;
        sprice.push_back(make_pair(b,a));
    }
    for(int i = 0; i<r; i++)
    {
        int a;
        cin>>a;
        rprice.push_back(a);
    }
    sort(sprice.begin(),sprice.end(),cmp2);
    sort(rprice.begin(),rprice.end(),cmp);
    sort(milk.begin(),milk.end(),cmp);
    for(int i = 1; i<r+1; i++)
    {
        rent[i]=rent[i-1]+rprice[i-1];
    }
    int i = 1;
    long long sum,nmilk;
    sum=nmilk=0;
    long long currentp,currentn;
    currentp=currentn=0;
    bool bye = false;
    while(true)
    {
        if(i==n+1)
            break;
        nmilk = milk[i-1];
        for(int j = currentp; j<m; j++)
        {
            if(sprice[j].second-currentn>nmilk)
            {
                sum+=nmilk*sprice[j].first;
                currentn +=nmilk;
                break;
            }
            else
            {
                sum+=(sprice[j].second-currentn)*sprice[j].first;
                nmilk-=(sprice[j].second-currentn);
                currentn = 0;
                currentp++;
            }
        }
        if(currentp==m)
        {
            bye = true;
            for(int j = i; j<n+1; j++)
            {
                sell[j]=sum;

            }
        }
        if(bye==true)
            break;
        sell[i]=sum;
        i++;
    }
    long long tot = -1;
    if(r<=n) {
        for (int j = 0; j < r + 1; j++) {
            tot = max(tot, rent[j] + sell[n - j]);
        }
    }
    else
    {
        for (int j = 0; j < n+1; j++) {
            tot = max(tot, rent[j] + sell[n - j]);
        }
    }
    cout<<tot;
}
