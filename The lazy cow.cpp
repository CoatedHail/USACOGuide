#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"
#include "set"
#include "stack"
#include "map"
#include "limits.h"
#include "cstdio"
#include "math.h"
#include <iomanip>
#include <numeric>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("lazy.in", "r", stdin);
    freopen("lazy.out", "w", stdout);
    int matrix[401][401];
    int n,k;
    cin>>n>>k;
    for(int i = 0; i<=n; i++)
    {
        for(int j = 0; j<=n; j++)
        {
            matrix[i][j]=0;
        }
    }
    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=n; j++)
        {
            cin>>matrix[i][j];
            matrix[i][j]+=matrix[i][j-1];
        }
    }

    int ans=0;
    for(int i = 1;i<n+1;i++){
        for(int j = 1;j<n+1;j++){
            int sum=0;
            for(int m = max(0,i-k); m< min(n+1,i+k+1); m++){
                sum+=matrix[m][min(n,j+(k-abs(i-m)))]-matrix[m][max(0,j-(k-abs(i-m))-1)];
            }
            ans= max(ans,sum);
        }
    }
    cout<<ans;
}
