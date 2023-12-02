#include <iostream>
#include <math.h>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <cstdio>

using namespace std;

const int mod = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    vector<long long> dp(200005);
    for(int i =0 ; i<9; i++)
        dp[i]=2;
    dp[9]=3;
    for(int i = 10; i<200005; i++)
        dp[i]=(dp[i-9]+dp[i-10])%mod;
    while(t--)
    {
        int n;
        cin>>n;
        int k;
        cin>>k;
        int ans = 0;
        while(n>0)
        {
            int x = n%10;
            if(k+x<10)
                ans+=1;
            else
                ans +=dp[k+x-10];
            ans%=mod;
            n/=10;
        }
        cout<<ans<<endl;
    }
}
