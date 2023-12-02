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
    int n,k;
    cin>>n>>k;
    vector<vector<int>> times(4);
    vector<vector<int>> sums(4);
    for(int i =0; i<n; i++)
    {
        int t,a,b;
        cin>>t>>a>>b;
        times[a*2+b].push_back(t);
    }
    for(int i = 0; i<4; i++)
    {
        sort(times[i].begin(),times[i].end());
        sums[i].push_back(0);
        for(auto it: times[i])
        {
            sums[i].push_back(sums[i].back()+it);
        }
    }
    int ans = INT_MAX;
    for(int i = 0; i<min(k + 1, int(sums[3].size())); i++)
    {
        if(k-i<int(sums[1].size())&&k-i<int(sums[2].size()))
            ans = min(ans,sums[3][i] + sums[1][k - i] + sums[2][k - i]);
    }
    if(ans == INT_MAX)
        cout<<-1;
    else
        cout<<ans;
}
