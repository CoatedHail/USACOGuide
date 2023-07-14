#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"
#include "set"
#include "stack"
#include "map"
#include "limits.h"
#include "cstdio"
#include "math.h"
#include <iomanip>
#include <numeric>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);
    int matrix[1001][1001];
    int n,m;
    cin>>n>>m;
    for(int i = 0; i<1001; i++)
    {
        for(int j = 0; j<1001; j++)
        {
            matrix[i][j]=0;
        }
    }
    for(int i = 0; i<n; i++)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        matrix[x1][y1]+=1;
        matrix[x2][y2]+=1;
        matrix[x1][y2]--;
        matrix[x2][y1]--;
    }
    int ans = 0;
    for (int x = 0; x < 1001; x++) {
        for (int y = 0; y < 1001; y++) {
            if (x > 0) matrix[x][y] += matrix[x - 1][y];
            if (y > 0) matrix[x][y] += matrix[x][y - 1];
            if (x > 0 && y > 0) matrix[x][y] -= matrix[x - 1][y - 1];
            if(matrix[x][y]==m)
                ans++;
        }
    }
    cout << ans << endl;
}
