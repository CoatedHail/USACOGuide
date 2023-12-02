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
    freopen("feast.in", "r", stdin);
    freopen("feast.out", "w", stdout);
    int max,a,b;
    cin>>max>>a>>b;
    vector<vector<bool>> dp(max+1,vector<bool>(2,false));
    dp[0][0]=true;
    bool works = true;
    for(int i = 0; i<=max; i++)
    {
        int j = 0;
        if(i-a>=0&&!dp[i][j])
            dp[i][j]=dp[i-a][j];
        if(i-b>=0&&!dp[i][j])
            dp[i][j]=dp[i-b][j];
        if(j == 0&&!dp[i/2][1])
            dp[i/2][1]=dp[i][j];

    }
    for(int i = 0; i<=max; i++)
    {
        int j = 1;
        if(i-a>=0&&!dp[i][j])
            dp[i][j]=dp[i-a][j];
        if(i-b>=0&&!dp[i][j])
            dp[i][j]=dp[i-b][j];

    }
    for(int i = max; i>=0; i--)
    {
        if(dp[i][0]||dp[i][1])
        {
            cout<<i;
            return 0;
        }
    }
}