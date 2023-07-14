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

int n,m,lit = 0;
bool light[101][101],visited[101][101];
vector<pair<int,int>> turn[101][101];
void turnon(int x, int y){
    if(!light[x][y]||visited[x][y]||x<1||y<1||x>n||y>n)
        return;
    visited[x][y]=true;
    for(auto room: turn[x][y])
    {
        if(!light[room.first][room.second])
            lit++;
        light[room.first][room.second]=true;
        if(visited[room.first+1][room.second]||visited[room.first-1][room.second]||visited[room.first][room.second+1]||visited[room.first][room.second-1])
            turnon(room.first,room.second);
    }
    turnon(x,y+1);
    turnon(x,y-1);
    turnon(x+1,y);
    turnon(x-1,y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("lightson.in", "r", stdin);
    freopen("lightson.out", "w", stdout);
    cin>>n>>m;
    for(int i = 0; i<m; i++)
    {
        int x,y,a,b;
        cin>>x>>y>>a>>b;
        turn[x][y].push_back(make_pair(a,b));
    }
    light[1][1]=true;
    turnon(1,1);
    cout<<lit+1;
}

