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
    int t;
    cin>>t;
    for(int test = 0; test<t; test++)
    {
        int n;
        cin>>n;
        vector<int> boss;
        for(int i = 0; i<n; i++)
        {
            int num;
            cin>>num;
            boss.push_back(num);
        }
        vector<vector<int>> dp(2,vector<int>(n+1,1e9));
        dp[1][0]=0;
        for(int i = 0; i<n; i++)
        {
            dp[0][i+1]=min(dp[0][i+1],dp[1][i]+boss[i]);
            dp[1][i+1]=min(dp[1][i+1],dp[0][i]);
            if(i+2<=n)
            {
                dp[0][i+2]=min(dp[0][i+2],dp[1][i]+boss[i]+boss[i+1]);
                dp[1][i+2]=min(dp[1][i+2],dp[0][i]);
            }
        }
        cout<<min(dp[0][n],dp[1][n])<<endl;
    }
}