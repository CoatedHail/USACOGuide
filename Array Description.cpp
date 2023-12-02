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

const int MOD = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> dp(n,vector<int>(m+1,0));
    int x0;
    cin>>x0;
    if(x0==0)
        fill(dp[0].begin(),dp[0].end(),1);
    else
        dp[0][x0]=1;
    for(int i = 1; i<n; i++)
    {
        int x;
        cin>>x;
        if(x==0)
        {
            for(int j  = 1; j<=m; j++)
            {
                for(int k : {j-1,j,j+1})
                {
                    if(k>=1&&k<=m) {
                        dp[i][j] += dp[i - 1][k];
                        dp[i][j]%=MOD;
                    }
                }
            }
        }
        else
        {
            for(int k : {x-1,x,x+1})
            {
                if(k>=1&&k<=m) {
                    dp[i][x] += dp[i - 1][k];
                    dp[i][x]%=MOD;
                }
            }
        }
    }
    int ans = 0;
    for(int j = 1; j<=m; j++)
    {
        ans+=dp[n-1][j];
        ans%=MOD;
    }
    cout<<ans;
}