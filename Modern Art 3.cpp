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
    vector<int> v(n);
    for(int i = 0; i<n; i++) {
        cin >> v[i];
    }
    vector<vector<int>> dp(n,vector<int>(n,-1));
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            dp[i][j]=301;
        }
    }
    for(int i = 0; i<n; i++)
        dp[i][i]=1;
    for(int s = 0; s<n; s++)
    {
        for(int i = 0; i<n-s; i++)
        {
            for(int j = i; j<i+s; j++)
            {
                int k = i+s;
                if(v[i]==v[k])
                {
                    dp[i][k]=min(dp[i][k],dp[j+1][k]+dp[i][j]-1);
                }
                dp[i][k]=min(dp[i][k],dp[j+1][k]+dp[i][j]);
            }
        }
    }
    cout<<dp[0][n-1];
}
