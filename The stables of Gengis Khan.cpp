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
    int n,k;
    cin>>n>>k;
    vector<int> stables(k);
    for(int i = 0; i<k; i++)
        cin>>stables[i];
    stables.push_back(0);
    stables.push_back(n+1);
    sort(stables.begin(),stables.end());
    vector<vector<int>> dp(k+2,vector<int>(k+2,INT32_MAX));
    for (int i = 0; i < k + 2; i++) {
        dp[i][i] = 0;
        if (i + 1 < k + 2) {
            dp[i][i + 1] = stables[i + 1] - stables[i] - 1;
        }
        if (i + 2 < k + 2) {
            dp[i][i + 2] = stables[i + 2] - stables[i] - 1;
        }
    }
    for(int num=4; num<=k+2; num++)
    {
        for(int start = 0; start+num-1<k+2; start++)
        {
            int end=start+num-1;
            dp[start][end]=min(dp[start][end],dp[start][start+1]+dp[start+1][end]+stables[end]-stables[start+1]);
            dp[start][end]=min(dp[start][end],dp[end-1][end]+dp[start][end-1]+stables[end-1]-stables[start]);
            for (int top = start + 2; top < end - 1; top++) {
                dp[start][end] =min(dp[start][end],dp[start][top] + dp[top][end] +stables[end] - stables[start] - 1);
            }
        }
    }
    cout<<dp[0][k+1];
}
