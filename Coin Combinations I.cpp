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
    vector<long long> dp(x+1,0);
    dp[0]=1;
    for(int weight = 0; weight<=x; weight++)
    {
        for(int i = 1; i<=n; i++) {
            if(weight-coins[i-1]>=0)
            {
                dp[weight]+=dp[weight-coins[i-1]];
                dp[weight]= dp[weight]%(int)(1e9+7);
            }
        }
    }
    cout<<dp[x];
}