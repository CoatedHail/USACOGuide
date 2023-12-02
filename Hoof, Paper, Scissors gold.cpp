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
    freopen("hps.in","r",stdin);
    freopen("hps.out","w",stdout);
    int n,k;
    cin>>n>>k;
    vector<int> john;
    for(int i =0; i<n; i++)
    {
        char num;
        cin>>num;
        if(num=='H') {
            john.push_back(0);
        }
        else if(num=='P')
            john.push_back(1);
        else
            john.push_back(2);
    }
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (k+2,vector<int>(3)));
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<=k; j++)
        {
            for(int l = 0; l<3; l++)
            {
                if(l == john[i])
                {
                    dp[i][j][l]++;
                }
                dp[i+1][j+1][0]=max(dp[i+1][j+1][0],dp[i][j][l]);
                dp[i+1][j+1][1]=max(dp[i+1][j+1][1],dp[i][j][l]);
                dp[i+1][j+1][2]=max(dp[i+1][j+1][2],dp[i][j][l]);
                dp[i+1][j][l]=max(dp[i+1][j][l],dp[i][j][l]);
            }
        }
    }
    int ret = 0;
    for(int i = 0; i<3; i++)
    {
        ret= max(ret, dp[n-1][k][i]);
    }
    cout<<ret;
}
