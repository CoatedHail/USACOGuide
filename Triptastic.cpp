#include <iostream>
#include <math.h>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cstdio>

using namespace std;

int n, m, k;
vector<vector<long long>> prefix;
vector<vector<long long>> grid;
long long sum(int row1, int column1, int row2, int column2)
{
    if(row1<0)
        row1=0;
    if(column2>=m)
        column2 = m-1;
    if(row2>=n)
        row2=n-1;
    if(column1<0)
        column1=0;
    long long tot = prefix[row2][column2];
    if(row1>0)
        tot-=prefix[row1-1][column2];
    if(column1>0)
        tot-=prefix[row2][column1-1];
    if(row1>0&&column1>0)
        tot+=prefix[row1-1][column1-1];
    return tot;
}
bool test(long long curr)
{
    for(long long i = 0; i<n; i++)
    {
        for(long long j = 0; j<m; j++)
        {
            if(sum(i-curr,j-curr,i+curr,j+curr)>=k+1&&grid[i][j]>0)
                return true;
        }
    }
    return false;
}

long long binary(long long l, long long r)
{
    r++;
    while(l<r) {
        int medium = l + (r - l) / 2;
        if (test(medium)) {
            r = medium;
        } else
            l = medium + 1;
    }
    return r;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int i = 0; i<t; i++)
    {
        cin>>n>>m>>k;
        grid.clear();
        prefix.clear();
        int total = 0;
        for(int j = 0; j<n; j++)
        {
            vector<long long> row;
            for(int g = 0; g<m; g++)
            {
                int num;
                cin>>num;
                row.push_back(num);
                total+=num;
            }
            grid.push_back(row);
            prefix.push_back(row);
        }
        if(total<k+1) {
            cout << -1;
            continue;
        }
        for(int j = 0; j<n; j++) {
            for (int g = 0; g < m; g++) {
                if(j>0)
                    prefix[j][g]+=prefix[j-1][g];
                if(g>0)
                    prefix[j][g]+=prefix[j][g-1];
                if(j>0&&g>0)
                    prefix[j][g]-=prefix[j-1][g-1];
            }
        }
        cout<<binary(0,max(n,m))<<endl;
    }
}