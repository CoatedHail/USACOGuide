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
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
    int X,Y,K,M;
    cin>>X>>Y>>K>>M;
    int dist[101][101];
    for(int i = 0; i<101; i++)
    {
        for(int j = 0; j<101; j++)
        {
            dist[i][j]=1e9+7;
        }
    }
    queue<pair<int,int>> q;
    q.push(make_pair(0,0));
    dist[0][0]=0;
    while(!q.empty()){
        auto top = q.front();
        q.pop();
        int ndist = dist[top.first][top.second]+1;
        int pourX = min(top.first,Y-top.second);
        int pourY = min(top.second,X-top.first);
        int nx[] = {top.first,0,X,top.first,top.first-pourX,top.first+pourY};
        int ny[] = {0,top.second,top.second,Y,top.second+pourX,top.second-pourY};
        for(int i = 0; i<6; i++)
        {
            if(ndist>K||dist[nx[i]][ny[i]]!=1e9+7)
                continue;
            dist[nx[i]][ny[i]]=ndist;
            q.push(make_pair(nx[i],ny[i]));
        }

    }
    int ret = INT_MAX;
    for(int i = 0; i<101; i++)
    {
        for(int j = 0; j<101; j++)
        {
            if(dist[i][j]<=K)
                ret = min(ret,abs(i+j-M));
        }
    }
    cout<<ret;
}

