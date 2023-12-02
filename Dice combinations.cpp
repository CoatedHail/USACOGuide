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



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<long long> dp(n+1);
    dp[0]=1;
    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=6; j++)
        {
            if(i-j<0)
                break;
            dp[i]+=dp[i-j];
        }
        dp[i]=dp[i]%1000000007;
    }
    cout<<dp[n];

}