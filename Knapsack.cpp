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
    int limit, n;
    cin>>limit>>n;
    map<int, vector<pair<int,int>>> weight;
    for(int i = 0; i<n; i++)
    {
        int value,wei,amt;
        cin>>value>>wei>>amt;
        if(wei<=limit&&amt>0)
            weight[wei].push_back(make_pair(value,amt));
    }
    vector<vector<long long>> dp(weight.size()+1,vector<long long>(limit+1,INT32_MIN));
    dp[0][0]=0;
    int at = 1;
    for(auto &[w,items]:weight)
    {
        sort(items.begin(),items.end(),greater<pair<int,int>>());
        for(int i = 0; i<=limit; i++)
        {
            dp[at][i]=dp[at-1][i];
            int copies = 0;
            int typeat = 0;
            int used = 0;
            long long profit = 0;
            while((copies+1)*w<=i&&typeat<items.size())
            {
                copies++;
                profit+=items[typeat].first;
                if(dp[at-1][i-copies*w]!=INT_MAX)
                {
                    dp[at][i]= max(dp[at][i],dp[at-1][i-copies*w]+profit);
                }
                used++;
                if(used == items[typeat].second)
                {
                    used = 0;
                    typeat++;
                }
            }
        }
        at++;
    }
    cout<<*max_element(dp.back().begin(),dp.back().end());
}