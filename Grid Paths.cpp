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
    vector<vector<bool>> grid(n,vector<bool>(n));
    for(int i =0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            char c;
            cin>>c;
            if(c=='.')
                grid[i][j]=true;
            else
                grid[i][j]=false;
        }
    }
    vector<vector<int>> dp(n,vector<int>(n));
    dp[0][0]=1;
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            if(!grid[i][j])
                dp[i][j]=0;
            else
            {
                if(i>0)
                    dp[i][j]+=dp[i-1][j];
                if(j>0)
                    dp[i][j]+=dp[i][j-1];
                dp[i][j]%=1000000007;
            }
        }
    }
    cout<<dp[n-1][n-1];
}