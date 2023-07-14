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
    freopen("ccski.in", "r", stdin);
    freopen("ccski.out", "w", stdout);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> elevation(n);
    vector<vector<int>> waypoints(n);
    int sele,bele;
    sele = INT_MAX;
    bele = -1;
    int arrayx[4] = {1, 0, -1, 0};
    int arrayy[4] = {0, 1, 0, -1};
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            int num;
            cin>>num;
            elevation[i].push_back(num);
            if(num>bele)
                bele = num;
            if(num<sele)
                sele=num;
        }
    }
    int x,y;
    int numway=0;
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            int num;
            cin>>num;
            waypoints[i].push_back(num);
            if(num==1)
            {
                x=i;
                y=j;
                numway = 0;
            }
        }
    }
    int l = 0;
    int r = bele-sele;
    while(l<r)
    {
        int D = (l+r)/2;
        int count = 0;
        queue<pair<int,int>>q;
        q.push(make_pair(x,y));
        vector<vector<bool>> visited(501,vector<bool>(501,false));
        while(!q.empty())
        {
            auto top = q.front();
            q.pop();
            for (int k = 0; k < 4; k++) {
                int newx = top.first + arrayx[k];
                int newy = top.second + arrayy[k];
                if (newx < 0 || newx > n - 1 || newy < 0 || newy > m - 1||
                    visited[newx][newy]) {
                    continue;
                }
                if(abs(elevation[newx][newy]-elevation[top.first][top.second])>D)
                {
                    continue;
                }
                q.push(make_pair(newx,newy));
                visited[newx][newy]=true;
            }
        }
        bool works = true;
        for(int i = 0; i<n; i++)
        {
            for(int j =0; j<m; j ++)
            {
                if(waypoints[i][j]==1&&visited[i][j]==false)
                    works = false;
            }
        }
        if(works)
            r = D;
        else
            l = D+1;
    }
    cout<<r;
}

