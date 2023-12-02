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
    freopen("cowrun.in", "r", stdin);
    freopen("cowrun.out", "w", stdout);
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i<n; i++)
        cin>>v[i];
    sort(v.begin(),v.end());
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n+1,vector<int>(2,INT_MAX)));
    for(int i = n-1; i>=0; i--)
    {
        for(int j = i; j<n; j++) {
            if(i==j)
            {
                dp[i][j][0] = abs(v[i]) * n;
                dp[i][j][1] = abs(v[j]) * n;
            }
            else
            {
                int remaining = n-(j-i);
                if(i<n)
                {
                    dp[i][j][0] = min(dp[i + 1][j][0] +(abs(v[i + 1] - v[i]) * remaining),dp[i + 1][j][1] + (abs(v[j] - v[i]) * remaining));
                }
                if(j>0)
                {
                    dp[i][j][1] = min(dp[i][j-1][1]+(abs(v[j-1]-v[j])*remaining),dp[i][j - 1][0] + (abs(v[j] - v[i]) * remaining));
                }
            }

        }

    }
    cout << min(dp[0][n - 1][0], dp[0][n - 1][1]) << endl;
}
