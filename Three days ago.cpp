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
    string s;
    cin>>s;
    map<vector<int>,long long> mp;
    vector<int> count(10,0);
    mp[count]++;
    for(auto x : s)
    {
        count[x-'0']++;
        count[x-'0']%=2;
        mp[count]++;
    }
    long long ans = 0;
    for(auto x : mp)
    {
        long long z = x.second;
        ans+=(z*(z-1))/2;
    }
    cout<<ans;
}
