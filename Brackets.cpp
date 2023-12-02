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

int N,K;
vector<int> val,b;
vector<vector<int>> dp;
int solve(int i, int j)
{
    if(i>=j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans = 0;
    ans = max(ans, solve(i+1,j));
    ans = max(ans,solve(i,j-1));
    for(int k = i+1; k<=j; k++)
    {
        if(b[i]+K==b[k])
            ans = max(ans, val[i] + val[k] + solve(i+1, k-1) + solve(k+1, j));
    }
    return dp[i][j]=ans;
}
void sol(){
    cin>>N>>K;
    val.resize(N+1);
    b.resize(N+1);
    dp.resize(N+1,vector<int>(N+1,-1));
    for (int i = 0; i < N; i++) cin >> val[i];
    for (int i = 0; i < N; i++) cin >> b[i];
    cout << solve(0, N-1) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sol();
}
