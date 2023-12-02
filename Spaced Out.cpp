#include <iostream>
#include <math.h>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <cstdio>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<vector<int>> grid(n + 1, vector<int>(n + 1));
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j<n; j++)
            cin>>grid[i][j];
    }
    long long horians,vertans;
    horians=vertans=0;
    for(int i = 0; i<n; i++)
    {
        vector<long long> sums(2);
        sums[0]=0;
        sums[1]=0;
        for(int j = 0; j<n; j++)
            sums[j%2]+=grid[i][j];
        horians +=max(sums[0],sums[1]);
    }
    for(int i = 0; i<n; i++)
    {
        vector<long long> sums(2);
        sums[0]=0;
        sums[1]=0;
        for(int j = 0; j<n; j++)
            sums[j%2]+=grid[j][i];
        vertans+=max(sums[0],sums[1]);
    }
    cout<<max(horians,vertans);
}
