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
int n;
vector<int> v1,v2;
int add(int a, int b)
{
    return(abs(v1[a]-v2[b])<=4);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("nocross.in", "r", stdin);
    freopen("nocross.out", "w", stdout);
    cin>>n;
    v1.resize(n+1);
    v2.resize(n+1);
    for(int i = 0; i<n; i++)
        cin>>v1[i+1];
    for(int i = 0; i<n; i++)
        cin>>v2[i+1];
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int i = 1; i<=n; i++)
    {
        for(int j =1 ; j<=n; j++)
        {
            dp[i][j]=max(dp[i][j],dp[i-1][j-1]+add(i,j));
            dp[i][j]=max(dp[i][j],dp[i-1][j]);
            dp[i][j]=max(dp[i][j],dp[i][j-1]);
        }
    }
    cout<<dp[n][n];
}
