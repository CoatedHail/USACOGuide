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

bool is_prime(long long n)
{
    for(long long i = 2; i*i<=n; i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("exercise.in", "r", stdin);
    freopen("exercise.out", "w", stdout);
    long long N,M;
    cin>>N>>M;
    vector<long long> dp(N+1),dp2(N+1);
    dp[0]=1;
    for(long long i = 2; i<=N; i++)
    {
        if(!is_prime(i))
            continue;
        for(long long k = 0; k<=N; k++)
        {
            dp2[k]=0;
        }
        for(long long k = 0; k<N; k++)
        {
            for(long long j = i; j+k<=N; j*=i)
            {
                dp2[j+k]+=dp[k]*j;
                dp2[j+k]%=M;
            }
        }
        for(long long k = 0; k<=N; k++)
        {
            dp[k]+=dp2[k];
            dp[k]%=M;
        }
    }
    long long ans = 0;
    for(long long i = 0; i<=N; i++) {
        ans += dp[i];
        ans%=M;
    }
    cout<<ans;
}
