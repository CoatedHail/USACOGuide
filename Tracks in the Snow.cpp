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
#include <numeric>
using namespace std;

int dx[4]{1, -1, 0, 0}, dy[4]{0, 0, 1, -1};
int n,m,ans = 1;
vector<vector<int>> depth(4000,vector<int>(4000));
vector<string> snow(4000);
bool inside(int x,int y)
{
    return (x > -1 && x < n && y > -1 && y < m && snow[x][y] != '.');
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i = 0; i<n; i++)
        cin>>snow[i];
    deque<pair<int,int>>q;
    q.push_back({0,0});
    depth[0][0]=1;
    while (q.size()) {
        pair<int, int> c = q.front();
        q.pop_front();
        ans = max(ans, depth[c.first][c.second]);

        for (int i = 0; i < 4; i++) {
            int x = c.first + dx[i], y = c.second + dy[i];
            if (inside(x, y) && depth[x][y] == 0) {
                if (snow[x][y] == snow[c.first][c.second]) {
                    depth[x][y] = depth[c.first][c.second];
                    q.push_front({x, y});
                } else {
                    depth[x][y] = depth[c.first][c.second] + 1;
                    q.push_back({x, y});
                }
            }
        }
    }

    cout << ans;
}