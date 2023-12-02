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

int n,k,want;
vector<vector<int>> grid,dp(805,vector<int>(805));

int query(int topleftr, int topleftc, int bottomrightr, int bottomrightc)
{
    return dp[bottomrightr][bottomrightc]-dp[bottomrightr][topleftc-1]-dp[topleftr-1][bottomrightc]+dp[topleftr-1][topleftc-1];
}
bool ok(int x)
{
    for(int r = 1; r<=n; r++)
    {
        for(int c = 1; c<=n; c++)
        {
            dp[r][c]=0;
        }
    }
    for(int r = 1; r<=n; r++)
    {
        for(int c= 1; c<=n; c++)
        {
            dp[r][c]= dp[r-1][c]+dp[r][c-1]-dp[r-1][c-1];
            if(grid[r-1][c-1]<=x)
                dp[r][c]++;
            if(r-k+1>=1&&c-k+1>=1&&query(r-k+1,c-k+1,r,c)>=want)
                return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    want = k*k/2+k%2;
    grid = vector<vector<int>> (n,vector<int>(n));
    for(int i = 0; i<n; i++)
    {
        for(int j =0; j<n; j++)
        {
            cin>>grid[i][j];
        }
    }
    int l = 0;
    int r = 1e9;
    int ans=-1;
    while(l<=r)
    {
        int mid = (l+r+1)/2;
        if(ok(mid))
        {
            ans = mid;
            r = mid-1;
        }
        else
        {
            l = mid+1;
        }
    }
    cout<<ans;
}