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
    int t;
    cin >> t;
    int arrayx[4] = {1, 0, -1, 0};
    int arrayy[4] = {0, 1, 0, -1};

    for (int tc = 0; tc < t; tc++) {
        char grid[51][51];
        int numgood=0;
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
                if(grid[i][j]=='G')
                    numgood++;
            }
        }
        if(numgood==0)
        {
            cout<<"Yes"<<endl;
            continue;
        }
        bool works = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'B') {
                    if (i > 0 && grid[i - 1][j] == '.')
                        grid[i - 1][j] = '#';
                    if (i < n - 1 && grid[i + 1][j] == '.')
                        grid[i + 1][j] = '#';
                    if (j > 0 && grid[i][j - 1] == '.')
                        grid[i][j - 1] = '#';
                    if (j < m - 1 && grid[i][j + 1] == '.')
                        grid[i][j + 1] = '#';
                    if (grid[i - 1][j] == 'G' && i > 0)
                        works = false;
                    if (grid[i + 1][j] == 'G' && i < n - 1)
                        works = false;
                    if (grid[i][j - 1] == 'G' && j > 0)
                        works = false;
                    if (grid[i][j + 1] == 'G' && j < m - 1)
                        works = false;
                }
            }
        }
        if(grid[n-1][m-1]=='#')
        {
            works = false;
            cout<<"No"<<endl;
            continue;
        }
        stack<pair<int, int>> s;
        s.push(make_pair(n-1, m-1));
        vector<vector<bool>> visited(51, vector<bool>(51));
        visited[n-1][m-1] = true;
        while (!s.empty()) {
            auto top = s.top();
            s.pop();
            for (int k = 0; k < 4; k++) {
                int newx = top.first + arrayx[k];
                int newy = top.second + arrayy[k];
                if (newx < 0 || newx > n - 1 || newy < 0 || newy > m - 1 || grid[newx][newy] == '#' ||
                    visited[newx][newy]) {
                    continue;
                }
                s.push(make_pair(newx, newy));
                visited[newx][newy] = true;
            }
        }
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<m; j++)
            {
                if(grid[i][j]=='G'&&visited[i][j]==false)
                    works = false;
            }
        }
        if(!works)
            cout<<"No"<<endl;
        else
            cout<<"Yes"<<endl;
    }
}

