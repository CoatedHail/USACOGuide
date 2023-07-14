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

int MN = 400010;
vector<bool> visited(MN,false);
vector<vector<int>> adj(MN);
vector<int> one,two;
vector<int> team(MN,0);
void dfs(int node) {
    visited[node] = true;
    for (auto u: adj[node]) {
        if (!visited[u]) {
            team[u] = 3-team[node];
            if (team[u] == 1) one.push_back(u);
            else if (team[u] == 2) two.push_back(u);
            dfs(u);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, m, a, b, tracker = 0; // tracker shifts indices rather than resetting arrays
    cin >> t;
    for (int i=0; i<t; i++) {
        one.push_back(tracker + 1);
        cin >> n >> m;
        for (int j=0; j<m; j++) {
            cin >> a >> b;
            adj[tracker + a].push_back(tracker + b);
            adj[tracker + b].push_back(tracker + a);
        }
        team[tracker + 1] = 1;
        dfs(tracker + 1);
        if (one.size() <= two.size()) {
            cout << one.size() << endl;
            for (int k=0; k <one.size(); k++) {
                cout << one[k] - tracker << " ";
            }
        }
        else {
            cout << two.size() << endl;
            for (int k=0; k<two.size(); k++) {
                cout << two[k] - tracker << " ";
            }
        }
        cout << endl;
        one.clear();
        two.clear();
        tracker += n;
    }
}