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

char grid[1001][1001];
bool visited[1001][1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            cin>>grid[i][j];
            visited[i][j]=false;
        }
    }
    int arrayx[4]={1,0,-1,0};
    int arrayy[4]={0,1,0,-1};
    int count = 0;
    for(int i = 0; i<n; i++)
    {
        for(int j= 0; j<m; j++)
        {
            stack<pair<int,int>> s;
            if(grid[i][j]=='#'||visited[i][j]==true)
                continue;
            s.push(make_pair(i,j));
            while(!s.empty())
            {
                auto top = s.top();
                s.pop();
                for(int k = 0; k<4; k++)
                {
                    int newx,newy;
                    newx = top.first+arrayx[k];
                    newy = top.second+arrayy[k];
                    if(newx<0||newx>=n||newy<0||newy>=m||visited[newx][newy]||grid[newx][newy]=='#')
                        continue;
                    s.push(make_pair(newx,newy));
                    visited[newx][newy]=true;
                }
            }
            count++;
        }
    }
    cout<<count;
}