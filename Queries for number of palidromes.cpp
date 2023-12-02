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
    string s;
    cin>>s;
    int n = s.size();
    vector<vector<int>> dp(n,vector<int>(n));
    vector<vector<bool>> pal(n,vector<bool>(n));
    for(int i = n-1; i>=0; i--)
    {
        dp[i][i]=pal[i][i]=1;
        for(int j =i+1; j<n; j++)
        {
            pal[i][j]=(pal[i+1][j-1]||j-i==1)&&(s[i]==s[j]);
            dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1] + pal[i][j];
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        cout << dp[l - 1][r - 1] << "\n";
    }
}
