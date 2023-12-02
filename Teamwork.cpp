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
    //freopen("teamwork.in","r",stdin);
    //freopen("teamwork.out","w",stdout);
    int n,k;
    cin>>n>>k;
    vector<long long> skill;
    for(int i = 0; i<n; i++)
    {
        int num;
        cin>>num;
        skill.push_back(num);
    }
    vector<long long> dp(n+1,-1);
    dp[ 0]=0;
    long long maxy = -1;
    for(int i =0; i<n; i++)
    {
        dp[i+1]=max(dp[i+1], dp[i]+skill[i]);
        maxy = skill[i];
        for(int j = 1; j<k; j++)
        {
            if(i-j>=0)
            {
                maxy = max(maxy,skill[i-j]);
                dp[i+1]=max(dp[i+1],dp[i-j]+(j+1)*maxy);
            }
        }
    }
    cout<<dp[n];
}