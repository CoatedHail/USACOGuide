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
long long currA=0,currP=0;
long long area=0,peri=0;
int n;

void floodfill(int x,int y)
{
    if (x < 0 || x >= n || y < 0 || y >= n) {
        currP++;
        return;  // if outside grid
    }
    if (visited[x][y]) return;
    if (grid[x][y] == '.') {
        currP++;
        return;
    }
    visited[x][y] = true;
    if (grid[x][y] == '#') { currA++; }
    floodfill(x, y + 1);
    floodfill(x, y - 1);
    floodfill(x - 1, y);
    floodfill(x + 1, y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);
    cin>>n;
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            cin>>grid[i][j];
        }
    }
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            if(!visited[i][j]&&grid[i][j] == '#')
            {
                floodfill(i,j);
                if(area==currA)
                {
                    peri = min(peri,currP);
                }
                else if(currA>area)
                {
                    area = currA;
                    peri = currP;
                }
                currA = 0;
                currP  = 0;
            }
        }
    }
    cout<<area<<" "<<peri;
}