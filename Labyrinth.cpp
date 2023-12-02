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

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int n,m;
vector<vector<char>> grid(1000,vector<char>(1000));
vector<vector<bool>> visited(1000,vector<bool>(1000));
string step = "URDL";
vector<vector<int>> prevstep(1000,vector<int>(1000));


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    queue<pair<int,int>>q;
    pair<int,int> start,end;
    for(int i = 0; i<n; i++)
    {
        for(int j= 0; j<m; j++)
        {
            cin>>grid[i][j];
            if (grid[i][j] == 'A') {
                start = make_pair(i,j);
            } else if (grid[i][j] == 'B') {
                end = make_pair(i,j);
            }
        }
    }
    q.push(start);
    visited[start.first][start.second]=true;
    while(!q.empty())
    {
        pair<int,int> top = q.front();
        q.pop();
        for(int d = 0; d<4; d++)
        {
            pair<int,int> v = make_pair(top.first+dx[d],top.second+dy[d]);
            if(v.first<0||v.first>=n||v.second<0||v.second>=m) continue;
            if(grid[v.first][v.second]=='#') continue;
            if(visited[v.first][v.second]) continue;
            visited[v.first][v.second]=true;
            prevstep[v.first][v.second]=d;
            q.push(v);
        }
    }
    if (visited[end.first][end.second]) {
        cout << "YES" << endl;
        vector<int> steps;
        while (end != start) {
            int p = prevstep[end.first][end.second];
            steps.push_back(p);
            end = make_pair(end.first - dx[p], end.second - dy[p]);
        }
        reverse(steps.begin(), steps.end());
        cout << steps.size() << endl;
        for (char c : steps) { cout << step[c]; }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }

}
