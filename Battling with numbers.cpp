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
    long long n,m;
    cin>>n;
    unordered_map<long long, long long> primes;
    vector<long long> a(n),b(n);
    for(int i = 0; i<n; i++)
    {
        cin>>a[i];
    }
    for(int i = 0; i<n; i++)
    {
        cin>>b[i];
        primes[a[i]]+=b[i];
    }
    cin>>m;
    vector<long long> c(m),d(m);
    for(long long i =0 ; i<m; i++)
        cin>>c[i];
    for(long long i = 0; i<m; i++)
    {
        cin>>d[i];
        primes[c[i]]-=d[i];
    }
    long long count = 0;
    for(auto x:primes){
        if(x.second<0)
        {
            cout<<0;
            return 0;
        }
        else if(x.second!=0)
            count++;
    }
    long long ans = 1;
    for(long long i = 0; i<count; i++)
    {
        ans*=2;
        ans%=998244353;
    }
    cout<<ans;
}
