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
    long long n;
    cin >> n;
    vector<vector<long long>> dp(n+4,vector<long long>(n+4)),pal(n+4,vector<long long>(n+4));
    vector<long long> a(n+4);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i <= n+3; i++)
        for(int j = 0; j <= n+3; j++)
            dp[i][j]=0, pal[i][j]=true;
    for(long long i = n; i > 0; i--){
        for(long long j = i; j <= n; j++){
            dp[i][j]=100000;
            if(a[i-1]==a[j-1]) pal[i][j] = pal[i+1][j-1];
            else pal[i][j]=false;
        }
    }
    for(long long i = n; i>0; i--){
        for(long long j = i; j<=n; j++){
            for(long long x = i; x <= j; x++){
                if(pal[i][x]) dp[i][j]=min(dp[i][j], dp[x+1][j]+1);
                if(a[i-1]==a[x-1] and x>i+1)
                    dp[i][j] = min(dp[i][j], dp[i+1][x-1]+dp[x+1][j]);
            }
        }
    }
    cout << dp[1][n];
}
