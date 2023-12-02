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

const int MOD = 1e9+7;
int add(int a, int b) {
    if ((a += b) >= MOD) a -= MOD;
    return a;
}

int mul(int a, int b) { return int(1LL * a * b % MOD); }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int n;
    n = s.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1)),choose(n/2+1,vector<int>(n/2+1));
    choose[0][0]=1;
    for(int i = 0; i<=n/2; i++)
    {
        choose[i][0]=1;
        for(int j = 1; j<=i; j++)
        {
            choose[i][j]=add(choose[i - 1][j], choose[i - 1][j - 1]);
        }
    }
    for (int i = 0; i + 1 <= n; ++i) dp[i + 1][i] = 1;
    for (int i = n - 1; i >= 0; --i)
        for (int j = i + 1; j < n; j += 2) {
            for (int k = i + 1; k <= j; k += 2)
                if (s[i] == s[k]) {
                    int temp = mul(dp[i + 1][k - 1], dp[k + 1][j]);
                    temp = mul(temp, choose[(j - i + 1) / 2][(k - i + 1) / 2]);
                    dp[i][j] = add(dp[i][j], temp);
                }
        }
    cout << dp[0][n - 1];
}
