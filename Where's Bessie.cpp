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

int MAXN = 20;
vector<vector<char>> image(MAXN, vector<char>(MAXN));
vector<vector<bool>> visited(MAXN, vector<bool>(MAXN));

struct PCL{
    int i1,j1,i2,j2;
    bool subrect(PCL other)
    {
        return (i1>=other.i1&&j1>=other.j1&&i2<=other.i2&&j2<=other.j2);
    }
};
int imin,imax,jmin,jmax;
void floodfill(int i, int j, char color)
{
    if (i < imin || j < jmin || i > imax || j > jmax || visited[i][j] ||
        image[i][j] != color) {
        return;
    }
    visited[i][j] = true;
    floodfill(i+1,j,color);
    floodfill(i-1,j,color);
    floodfill(i,j+1,color);
    floodfill(i,j-1,color);
}
bool isPCL(int i1,int j1, int i2, int j2)
{
    vector<int> regions(26,0);
    imin = i1;
    imax = i2;
    jmin=j1;
    jmax = j2;
    for(int i = i1; i<=i2; i++)
    {
        for(int j = j1; j<=j2; j++)
        {
            if(!visited[i][j])
            {
                char curr = image[i][j];
                regions[image[i][j]-'A']++;
                floodfill(i,j,curr);
            }
        }
    }
    fill(visited.begin(),visited.end(),vector<bool>(MAXN,false));
    int colornum = 0;
    bool oneregion,tworegion;
    oneregion = false;
    tworegion = false;
    for(int i = 0; i<26; i++)
    {
        if(regions[i]>0)
            colornum++;
        if(regions[i]==1)
            oneregion = true;
        if(regions[i]>1)
            tworegion = true;
    }
    if(colornum ==2&&oneregion&&tworegion)
        return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("where.in", "r", stdin);
    freopen("where.out", "w", stdout);
    int n;
    cin>>n;
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            cin>>image[i][j];
        }
    }
    vector<PCL> list;
    for(int i1 = 0; i1<n; i1++)
    {
        for(int j1 = 0; j1<n; j1++)
        {
            for(int i2 = 0; i2<n; i2++)
            {
                for(int j2 = 0; j2<n; j2++)
                {
                    if(isPCL(i1,j1,i2,j2))
                        list.push_back({i1,j1,i2,j2});
                }
            }
        }
    }
    int pclcount = 0;
    for(int i = 0; i<list.size(); i++)
    {
        bool valid = true;
        for(int j = 0; j<list.size(); j++)
        {
            if(i==j)
                continue;
            if(list[i].subrect(list[j]))
            {
                valid = false;
                break;
            }
        }
        if(valid)
            pclcount++;
    }
    cout<<pclcount;
}

