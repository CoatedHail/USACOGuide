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
    int sumele = n*(n+1)/2;
    if(sumele%2==1) {
        cout << 0;
        return 0;
    }

    sumele /=2;
    vector<vector<int>> dp(n, vector<int> (sumele+1));
    dp[0][0]=1;
    // dp[i][j] = the number of ways to make sum j with the numbers from 1 to i
    for(int i = 1; i<n; i++)
    {
        for(int j = 0; j<=sumele; j++)
        {
            dp[i][j]+=dp[i-1][j];
            int prev = j-i;
            if(prev>=0)
                dp[i][j]+=dp[i-1][prev];
            dp[i][j]%=1000000007;
        }

    }
    cout<<dp[n-1][sumele];
}