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
    freopen("248.in", "r", stdin);
    freopen("248.out", "w", stdout);
    int n;
    cin>>n;
    vector<int> v(n);
    int best = 0;
    for(int i = 0; i<n; i++) {
        cin >> v[i];
        best = max(best,v[i]);
    }
    vector<vector<int>> dp(n,vector<int>(n,-1));
    for(int i = 1; i<=n; i++)
    {
        for(int j = 0; j+i-1<n; j++)
        {
            int r=j+i-1;
            if(j==r)
            {
                dp[j][r]=v[j];
                continue;
            }
            for(int rr = j; rr<r; rr++)
            {
                if(dp[j][rr]!=-1&&dp[j][rr]==dp[rr+1][r])
                {
                    dp[j][r]=max(dp[j][r],dp[j][rr]+1);
                }
            }
            best = max(best,dp[j][r]);
        }
    }
    cout<<best;
}
