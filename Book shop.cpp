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
    vector<int> cost(n),pages(n);
    for(int i = 0; i<n; i++)
        cin>>cost[i];
    for(int i = 0; i<n; i++)
    {
        cin>>pages[i];
    }
    vector<vector<int>> dp(n+1,vector<int> (x+1));
    for(int i = 1; i<=n; i++)
    {
        int currcost = cost[i-1];
        int currpage = pages[i-1];
        for(int j = 1; j<=x; j++)
        {
            dp[i][j]=dp[i-1][j];
            if(currcost<=j)
            {
                dp[i][j]=max(dp[i][j],dp[i-1][j-currcost]+currpage);
            }
        }
    }
    cout<<dp[n][x];
}