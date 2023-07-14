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

int MAXN = 200;
int n,cows;
vector<vector<int>> grid(MAXN,vector<int>(MAXN));

void floodfill(int r, int c)
{
    if(r<0||r>=n||c<0||c>=n||grid[r][c]>=2)
        return;
    else if(grid[r][c]==1)
        cows++;
    grid[r][c]=3;
    floodfill(r,c+1);
    floodfill(r,c-1);
    floodfill(r-1,c);
    floodfill(r+1,c);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("countcross.in", "r", stdin);
    freopen("countcross.out", "w", stdout);
    int k,r;
    cin>>n>>k>>r;
    n*=2;
    for(int i = 0; i<r; i++)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        x1--;
        y1--;
        x2--;
        y2--;
        x1*=2;
        y1*=2;
        x2*=2;
        y2*=2;
        if(x1==x2)
        {
            int t = (y1+y2)/2;
            grid[x1][t]=2;
            grid[x1+1][t]=2;
            if(x1>0)
                grid[x1-1][t]=2;
        }
        else
        {
            int t = (x1+x2)/2;
            grid[t][y1]=2;
            grid[t][y1+1]=2;
            if(y1>0)
                grid[t][y1-1]=2;
        }
    }
    for(int i = 0; i<k; i++)
    {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        a*=2;
        b*=2;
        grid[a][b]=1;
    }
    vector<int> v;
    for(int i = 0; i<n; i++) {
        for (int j = 0; j < n; j++)
        {
            if(grid[i][j]<2) {
                cows = 0;
                floodfill(i, j);
                v.push_back(cows);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i<v.size()-1; i++)
    {
        for(int j = i+1; j<v.size(); j++)
        {
            ans+=v[i]*v[j];
        }
    }
    cout<<ans;
}

