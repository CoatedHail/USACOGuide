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

int W,H,N;
vector<pair<int,int>> slabs;
vector<vector<int>> cal;
int dp(int height, int width)
{
    if(cal[height][width]!=-1)
        return cal[height][width];
    int mini = height*width;
    for(int i = 0; i<N; i++)
    {
        if(slabs[i].first>width||slabs[i].second>height)
            continue;
        mini = min(mini, dp(height-slabs[i].second,slabs[i].first)+dp(height,width-slabs[i].first));
        mini = min(mini, dp(height-slabs[i].second, width)+dp(slabs[i].second, width-slabs[i].first));
    }
    cal[height][width]=mini;
    return mini;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>W>>H;
    cin>>N;
    cal.resize(H+1,vector<int>(W+1,-1));
    for(int i = 0; i<N; i++)
    {
        int a,b;
        cin>>a>>b;
        slabs.push_back(make_pair(a,b));
    }
    cout<<dp(H,W);
}