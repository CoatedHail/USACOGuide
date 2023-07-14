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
    int n,q;
    cin>>n>>q;
    int matrix[1001][1001];
    for(int i = 0; i<1001; i++)
    {
        matrix[i][0]=0;
        matrix[0][i]=0;
    }
    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=n; j++)
        {
            char c;
            cin>>c;
            if(c=='.')
            {
                matrix[i][j]=matrix[i][j-1]+matrix[i-1][j]-matrix[i-1][j-1];
            }
            else
            {
                matrix[i][j]=matrix[i][j-1]+matrix[i-1][j]-matrix[i-1][j-1]+1;
            }
        }
    }
    for(int i = 0; i<q; i++)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        cout<<matrix[x2][y2]-matrix[x1-1][y2]-matrix[x2][y1-1]+matrix[x1-1][y1-1]<<endl;
    }
}
