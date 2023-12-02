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

long long dist(pair<int,int> a, pair<int,int> b)
{
    int x = abs(a.first-b.first);
    int y = abs(a.second-b.second);
    return x*x+y*y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("checklist.in", "r", stdin);
    freopen("checklist.out", "w", stdout);
    int h,g;
    cin>>h>>g;
    vector<pair<int,int>> hs(h),gs(g);
    for(int i = 0; i<h; i++)
        cin>>hs[i].first>>hs[i].second;
    for(int i = 0; i<g; i++)
        cin>>gs[i].first>>gs[i].second;
    vector<vector<vector<long long>>> dp(h+1, vector<vector<long long>>(g+1,vector<long long>(2,1e18)));
    dp[1][0][0]=0;
    for(int i = 0; i<=h; i++)
    {
        for(int j = 0; j<=g; j++)
        {
            if(i>1)
                dp[i][j][0]=min(dp[i][j][0],dp[i-1][j][0]+dist(hs[i-2],hs[i-1]));
            if(j>1)
                dp[i][j][1]=min(dp[i][j][1],dp[i][j-1][1]+dist(gs[j-2],gs[j-1]));
            if(i>0&&j>0)
            {
                dp[i][j][0]=min(dp[i][j][0],dp[i-1][j][1]+dist(hs[i-1],gs[j-1]));
                dp[i][j][1]=min(dp[i][j][1],dp[i][j-1][0]+dist(hs[i-1],gs[j-1]));
            }
        }
    }
    cout<<dp[h][g][0];
}