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



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    vector<int> dp;
    cin>>n;
    vector<int> height;
    for(int i =0; i<n; i++)
    {
        int num;
        cin>>num;
        height.push_back(num);
    }
    dp.resize(n,INT_MAX);
    dp[0]=0;
    for(int i = 0; i<n-1; i++)
    {
        dp[i+1]=min(dp[i+1],dp[i]+abs(height[i]-height[i+1]));
        if(i+2<n)
        {
            dp[i+2]=min(dp[i+2],dp[i]+abs(height[i]-height[i+2]));
        }
    }
    cout<<dp[n-1];
}
