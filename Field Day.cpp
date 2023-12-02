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
    int c,n;
    cin>>c>>n;
    vector<int> op(n);
    queue<int> graph;
    vector<int> dist((1<<c)+1,-1);
    for(int i = 0; i<n; i++)
    {
        string team;
        cin>>team;
        int mask = 0;
        for(int  i= 0; i<c; i++) {
            mask^=(team[i]-'G')<<i;
        }
        op[i]=~mask&((1<<c)-1);
        graph.push(mask);
        dist[mask]=c;
    }
    while(!graph.empty())
    {
        int mask = graph.front();
        graph.pop();
        for(int d = 0; d<c; d++)
        {
            int newmask = mask^(1<<d);
            if(dist[newmask]==-1)
            {
                dist[newmask]=dist[mask]-1;
                graph.push(newmask);
            }
        }
    }
    for(int i =0; i<n; i++)
    {
        cout<<dist[op[i]]<<endl;
    }
}