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
    int n,x;
    cin>>n>>x;
    vector<long long> coins;
    for(int i =0 ; i<n; i++)
    {
        int num;
        cin>>num;
        coins.push_back(num);
    }
    vector<long long> dp(x+1,INT_MAX);
    dp[0]=0;
    for(int i = 1; i<=n; i++)
    {
        for(int weight = 0; weight<=x; weight++)
        {
            if(weight-coins[i-1]>=0)
            {
                dp[weight]=min(dp[weight],dp[weight-coins[i-1]]+1);
            }
        }
    }
    if(dp[x]==INT_MAX)
        cout<<-1;
    else
        cout<<dp[x];
}