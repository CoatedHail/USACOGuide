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
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i<n; i++)
        cin>>v[i];
    vector<vector<bool>> dp(512,vector<bool>(512,false));
    for(int i = 0; i<512; i++)
        dp[0][i]=true;
    for(int a: v)
    {
        if(a==0)
            continue;
        for(int i =0; i<512; i++)
        {
            dp[a^i][a]=dp[a^i][a]||dp[i][a-1];
            if (dp[a ^ i][a]) {
                int j = a + 1;
                while (j < 512 && !dp[a ^ i][j]) { dp[a ^ i][j++] = true; }
            }
        }
    }
    vector<int> ans;
    for (int i = 0; i < 512; i++) {
        if (dp[i][511]) { ans.push_back(i); }
    }
    cout<<ans.size()<<endl;
    for(auto i: ans)
        cout<<i<<" ";
}
