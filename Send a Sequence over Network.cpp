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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> v(n+1,0);
        for(int i = 1; i<=n; i++)
            cin>>v[i];
        vector<bool> dp(n+1,false);
        dp[0]=true;
        for(int i = 1; i<=n; i++)
        {
            if(i+v[i]<=n&&dp[i-1])
                dp[i+v[i]]=true;
            if(i-v[i]-1>=0&&dp[i-v[i]-1])
                dp[i]=true;
        }
        if(dp[n])
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}
