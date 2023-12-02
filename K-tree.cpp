#include <iostream>
#include <math.h>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <cstdio>

using namespace std;

const int mod = 1e9+7;
void add(int &a, int b)
{
    a+=b;
    if(a>=mod)
        a-=mod;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k,d;
    cin>>n>>k>>d;
    vector<vector<int>> dp(n+1,vector<int>(2));
    dp[0][0]=1;
    dp[0][1]=0;
    for(int i = 1; i<=n; i++)
    {
        dp[i][0]=dp[i][1]=0;
        for(int j = 1; j<=k; j++)
        {
            if(i-j<0)
                break;
            if(j<d){
                add(dp[i][0],dp[i-j][0]);
                add(dp[i][1],dp[i-j][1]);
            }
            else
            {
                add(dp[i][1],dp[i-j][0]);
                add(dp[i][1],dp[i-j][1]);
            }
        }
    }
    cout<<dp[n][1];
}
