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

int dist(pair<int,int> a, pair<int,int> b)
{
    return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("radio.in", "r", stdin);
    freopen("radio.out", "w", stdout);
    int n,m,fx,fy,bx,by;
    cin>>n>>m;
    cin>>fx>>fy;
    cin>>bx>>by;
    vector<pair<int,int>> floc(n+1),bloc(m+1);
    floc[0].first = fx;
    floc[0].second = fy;
    bloc[0].first = bx;
    bloc[0].second = by;
    for(int i = 1; i<=n; i++)
    {
        char c;
        cin>>c;
        if(c=='N')
        {
            floc[i].first=floc[i-1].first;
            floc[i].second = floc[i-1].second+1;
        }
        else if(c=='S')
        {
            floc[i].first=floc[i-1].first;
            floc[i].second = floc[i-1].second-1;
        }
        else if(c=='W')
        {
            floc[i].first = floc[i-1].first-1;
            floc[i].second= floc[i-1].second;
        }
        else if(c=='E')
        {
            floc[i].first = floc[i-1].first+1;
            floc[i].second = floc[i-1].second;
        }
    }
    for(int i = 1; i<=m; i++)
    {
        char c;
        cin>>c;
        if(c=='N')
        {
            bloc[i].first=bloc[i-1].first;
            bloc[i].second = bloc[i-1].second+1;
        }
        else if(c=='S')
        {
            bloc[i].first=bloc[i-1].first;
            bloc[i].second = bloc[i-1].second-1;
        }
        else if(c=='W')
        {
            bloc[i].first = bloc[i-1].first-1;
            bloc[i].second= bloc[i-1].second;
        }
        else if(c=='E')
        {
            bloc[i].first = bloc[i-1].first+1;
            bloc[i].second = bloc[i-1].second;
        }
    }
    vector<vector<int>> dp(n+1,vector<int>(m+1,1e9+7));
    dp[0][0]=0;
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            dp[i+1][j]= min(dp[i+1][j],dp[i][j]+dist(floc[i+1],bloc[j]));
            dp[i][j+1]=min(dp[i][j+1],dp[i][j]+dist(floc[i],bloc[j+1]));
            dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]+dist(floc[i+1],bloc[j+1]));
        }
    }
    cout<<dp[n][m];
}