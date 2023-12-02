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
    vector<long long> dp(6,0);
    long long ans= 0;
    long long tot = 0;
    for(int i = 0; i<n; i++)
    {
        dp[0]++;
        if(s[i]=='b')
        {
            dp[1]+=dp[0];
            dp[0]=0;
        }
        else if(s[i]=='e')
        {
            dp[2]+=dp[1];
            dp[0]+=dp[5];
            ans+=dp[5];
            dp[5]=0;
            dp[1]=0;
        }
        else if(s[i]=='s')
        {
            dp[4]+=dp[3];
            dp[3]=0;
            dp[3]+=dp[2];
            dp[2]=0;
        }
        else if(s[i]=='i')
        {
            dp[5]+=dp[4];
            dp[4]=0;
        }
        tot+=ans;
    }
    cout<<tot;
}
