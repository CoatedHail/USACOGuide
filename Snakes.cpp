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
#include <iomanip>
#include <numeric>
using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("snakes.in","r",stdin);
    freopen("snakes.out","w",stdout);
    int n,k;
    cin>>n>>k;
    vector<long long> snakes(n+1);
    long long ans = 0;
    long long maxy = 0;
    vector<vector<long long>> dp(n+1,vector<long long>(k+1,INT_MAX));
    for(int i = 1; i<=n; i++)
    {
        cin>>snakes[i];
        maxy = max(maxy,snakes[i]);
        dp[i][0]=maxy*(i);
        for(int j = 1; j<=k; j++)
        {
            long long mx = snakes[i];
            for(int b= i-1; b>=0; b--)
            {
                dp[i][j]=min(dp[i][j],dp[b][j-1]+mx*(i-b));
                mx = max(mx,snakes[b]);
            }
        }
        ans+=snakes[i];
    }
    cout<<dp[n][k]-ans;
}