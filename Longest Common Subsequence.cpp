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
    vector<vector<int>> dp(a.size(),vector<int>(b.size(),0));
    for(int i = 0; i<a.size(); i++) {
        if (a[i] == b[0]) {
            dp[i][0] = 1;
        }
        if(i!=0)
        {
            dp[i][0]=max(dp[i][0], dp[i-1][0]);
        }
    }
    for(int i = 0; i<b.size(); i++)
    {
        if(b[i]==a[0]) dp[0][i]=1;
        if(i!=0) dp[0][i]=max(dp[0][i],dp[0][i-1]);
    }
    for(int i =1; i<a.size(); i++)
    {
        for(int j = 1; j<b.size(); j++)
        {
            if(a[i]==b[j])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout<<dp[a.size()-1][b.size()-1];
}