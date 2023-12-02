#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"
#include "set"
#include "unordered_set"
#include "stack"
#include "map"
#include "limits.h"
#include "cstdio"
#include "math.h"
#include <numeric>
using namespace std;

const int MAXN = 1e6;
const int MOD = 1e9+7;
long long fac[MAXN+1];
long long inv[MAXN+1];

long long exp(long long x, long long y, long long m)
{
    x%=m;
    long long res = 1;
    while(y>0)
    {
        if(y%2==1) res=res*x%m;
        x = x*x%m;
        y/=2;
    }
    return res;
}
void factorial()
{
    fac[0]=1;
    for(int i = 1; i<=MAXN; i++)
        fac[i]=fac[i-1]*i%MOD;
}
void inverse()
{
    inv[MAXN]=exp(fac[MAXN],MOD-2,MOD);
    for(int i = MAXN; i>=1; i--)
    {
        inv[i-1]=inv[i]*i%MOD;
    }
}

long long choose(int n, int r)
{
    return (fac[n]*inv[r]%MOD*inv[n-r]%MOD);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    factorial();
    inverse();
    int n;
    cin>>n;
    for(int i =0; i<n; i++)
    {
        int a,b;
        cin>>a>>b;
        cout<<choose(a,b)<<endl;
    }
}