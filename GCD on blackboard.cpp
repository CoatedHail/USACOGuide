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

int gcd(int a, int b)
{
    if(b==0)
        return a;
    a%=b;
    return gcd(b,a);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin>>N;
    vector<int> v;
    for(int i = 0; i<N; i++)
    {
        int num;
        cin>>num;
        v.push_back(num);
    }
    vector<int> pre(N+1,0);
    vector<int> suf(N+2,0);
    for(int i = 1; i<N+1; i++)
        pre[i]= gcd(pre[i-1],v[i-1]);
    for(int i = N; i>=1; --i)
    {
        suf[i]=gcd(suf[i+1],v[i-1]);
    }
    int ans = 0;
    for(int i = 1; i<=N; ++i)
    {
        ans = max(ans, gcd(pre[i-1],suf[i+1]));
    }
    if(ans!=0)
        cout<<ans;
    else
        cout<<1000000000;
}
