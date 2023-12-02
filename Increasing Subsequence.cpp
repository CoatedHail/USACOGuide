#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"
#include "set"
#include "unordered_set"
#include "stack"
#include "unordered_map"
#include "limits.h"
#include "cstdio"
#include "math.h"
#include <numeric>
using namespace std;

int find_lis(vector<int> a) {
    vector<int> dp;
    for (int i : a) {
        int pos = lower_bound(dp.begin(), dp.end(), i) - dp.begin();
        if (pos == dp.size()) {
            // we can have a new, longer increasing subsequence!
            dp.push_back(i);
        } else {
            // oh ok, at least we can make the ending element smaller
            dp[pos] = i;
        }
    }
    return dp.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> v;
    for(int i =0 ; i<n; i++)
    {
        int num;
        cin>>num;
        v.push_back(num);
    }
    cout<<find_lis(v);
}