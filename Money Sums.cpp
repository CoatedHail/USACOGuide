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
    vector<int> coins(n);
    for(int i = 0; i<n; i++)
        cin>>coins[i];
    vector<vector<int>> dp(101,vector<int>(100001));
    dp[0][0]=true;
    for(int i = 1; i<=n; i++)
    {
        for(int j = 0; j<=100000; j++)
        {
            dp[i][j]=dp[i-1][j];
            int prev = j-coins[i-1];
            if(prev>=0&&dp[i-1][prev])
                dp[i][j]=true;
        }
    }
    vector<int> possible;
    for(int i = 1; i<=100000; i++)
    {
        if(dp[n][i])
            possible.push_back(i);
    }
    cout<<possible.size()<<endl;
    for(auto x : possible)
        cout<<x<<" ";
}