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

vector<vector<bool>> present(3000,vector<bool>(3000));
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
queue<pair<int,int>> place;
void evaluate(int x, int y)
{
    if(!present[x][y])
    {
        return;
    }
    int num = 0;
    for(int i = 0; i<4; i++)
    {
        num+=present[x+dx[i]][y+dy[i]];
    }
    if(num==3)
    {
        for(int i = 0; i<4; i++)
        {
            if(!present[x+dx[i]][y+dy[i]])
            {
                place.push(make_pair(x+dx[i],y+dy[i]));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("mooyomooyo.in", "r", stdin);
    //freopen("mooyomooyo.out", "w", stdout);

    int N;
    cin>>N;


    int total = 0;
    for(int i = 1; i<=N; i++)
    {
        pair<int,int> p;
        cin>>p.first>>p.second;
        p.first+=1000;
        p.second+=1000;
        place.push(p);
        while(!place.empty())
        {
            auto top = place.front();
            place.pop();
            if(present[top.first][top.second])
            {
                continue;
            }
            total++;
            present[top.first][top.second]=1;
            evaluate(top.first,top.second);
            for(int k = 0; k<4; k++)
            {
                evaluate(top.first+dx[k],top.second+dy[k]);
            }
        }
        cout<<total-i<<endl;
    }
}

