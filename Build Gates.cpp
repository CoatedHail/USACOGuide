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
bool fence[4003][4003] = {false};
bool visited[4003][4003]= {false};
int maxx = 2001,minx = 2001, maxy = 2001, miny = 2001;

void ff(int i, int j) {
    if (i < minx || i > maxx || j < miny || j > maxy || visited[i][j] ||
        fence[i][j]) {
        return;
    }
    visited[i][j] = true;
    int x[] = {-1, 0, 0, 1}, y[] = {0, -1, 1, 0};
    for (int k = 0; k < 4; k++) { ff(i + x[k], j + y[k]); }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("gates.in", "r", stdin);
    freopen("gates.out", "w", stdout);
    int n;
    cin>>n;
    string path;
    cin>>path;
    int x = 2001,y = 2001;
    map<char,pair<int,int>> dir{{'N',{-1,0}},{'S', {1,0}},{'E',{0,1}},{'W',{0,-1}}};
    for(int i = 0; i<n; i++)
    {
        fence[x+dir[path[i]].first][y+dir[path[i]].second]=true;
        fence[x+2*dir[path[i]].first][y+2*dir[path[i]].second]=true;
        x += 2 * dir[path[i]].first;
        y += 2 * dir[path[i]].second;
        minx = min(minx, x);
        maxx = max(maxx, x);
        miny = min(miny, y);
        maxy = max(maxy, y);
    }
    minx--;
    maxx++;
    miny--;
    maxy++;
    int ans = 0;
    for(int i = minx; i<=maxx; i++)
    {
        for(int j = miny; j<=maxy; j++)
        {
            if(!visited[i][j]&&!fence[i][j])
            {
                ff(i,j);
                ans++;
            }
        }
    }
    cout<<ans-1;
}

