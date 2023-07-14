
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

vector<vector<bool>> connected;
vector<bool> visited;

int reach(int node)
{
    int influence=1;
    visited[node]=true;
    for(int i = 0; i<connected.size(); i++)
    {
        if(!visited[i]&&connected[node][i])
        {
            visited[i]=true;
            influence+=reach(i);
        }
    }
    return influence;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    int n;
    cin>>n;
    connected.resize(n,vector<bool>(n));
    vector<long long> x(n),y(n),power(n);
    for(int i =0; i<n; i++)
    {
        cin>>x[i]>>y[i]>>power[i];
    }
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            long long distsquared = abs(x[i]-x[j])*abs(x[i]-x[j])+abs(y[i]-y[j])*abs(y[i]-y[j]);
            connected[i][j] = distsquared<=power[i]*power[i];
        }
    }
    int maxc = -1;
    for(int i= 0; i<n; i++)
    {
        visited.clear();
        visited.resize(n,false);
        maxc = max(maxc,reach(i));

    }
    cout<<maxc;
}