#include <iostream>
#include <math.h>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cstdio>

using namespace std;

const int mod = 1e9+7;
long long n, m;
vector<string> vec;
vector<string> ans;
vector<pair<long long, long long>> points;
vector<vector<bool>> vis;
bool issafe(long long x, long long y)
{
    if(x>=0&&y>=0&&x<n&&y<m&&!vis[x][y]&&vec[x][y]!='.')
        return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        cin >> n >> m;
        vec.clear();
        ans.clear();
        points.clear();
        vis.resize(n+1,vector<bool>(m+1));
        bool check = true;
        for(long long i = 0; i<n; i++)
        {
            string s;
            cin>>s;
            ans.push_back(s);
            vec.push_back(s);
        }
        vector<char> row(n,'B');
        vector<char> col(m,'B');
        for(long long i = 0; i<n; i++)
        {
            for(long long j=0; j<m; j++)
            {
                if(vec[i][j]=='U')
                {
                    if(row[i]=='B')
                    {
                        ans[i][j]='W';
                        row[i]='W';
                        ans[i+1][j]='B';
                    }
                    else{
                        ans[i][j]='B';
                        row[i]='B';
                        ans[i+1][j]='W';
                    }
                }
                else if(vec[i][j]=='L')
                {
                    if(col[j]=='B')
                    {
                        ans[i][j]='W';
                        col[j]='W';
                        ans[i][j+1]='B';
                    }
                    else
                    {
                        ans[i][j]='B';
                        col[j]='B';
                        ans[i][j+1]='W';
                    }
                }
            }
        }
        check = true;
        for(long long i = 0; i<n; i++)
        {
            if(row[i]!='B')
                check=false;
        }
        for(long long i = 0; i<m; i++)
        {
            if(col[i]!='B')
                check = false;
        }
        if(!check)
        {
            cout<<"-1"<<endl;
            continue;
        }
        for(auto i : ans)
            cout<<i<<endl;
    }
}
