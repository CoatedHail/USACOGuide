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
    string a,b;
    cin>>a>>b;
    int siza,sizb;
    siza = a.size();
    sizb = b.size();
    vector<vector<int>> dp(siza+1,vector<int> (sizb+1,1e9));
    dp[0][0]=0;
    for(int i = 0; i<=siza; i++)
    {
        for(int j = 0; j<=sizb; j++)
        {
            if(i>0)
                dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
            if(j>0)
                dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
            if(i>0&&j>0)
                dp[i][j]=min(dp[i][j],dp[i-1][j-1]+(a[i-1]!=b[j-1]));
        }
    }
    cout<<dp[siza][sizb];
}