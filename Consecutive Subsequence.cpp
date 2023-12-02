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
    cin >> n;
    vector<int> arr(n);
    for (int &i : arr) { std::cin >> i; }
    map<int,int> dp;
    int ans = 0;
    int lst = 0;
    for(int i = 0; i<n; i++)
    {
        int x = arr[i];
        dp[x]=dp[x-1]+1;
        if(ans<dp[x])
        {
            ans = dp[x];
            lst = x;
        }
    }
    vector<int> res;
    for(int i = n-1; i>=0; i--)
    {
        if(arr[i]==lst)
        {
            res.push_back(i);
            lst--;
        }
    }
    reverse(res.begin(),res.end());
    cout<<ans<<endl;
    for(auto x:res)
        cout<<x+1<<" ";
}
