#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"
#include "set"
#include "unordered_set"
#include "stack"
#include "unordered_map"
#include "limits.h"
#include "cstdio"
#include "math.h"
#include <numeric>
using namespace std;

int N,M;
vector<vector<int>> adj;
int cycle_len(int start) {
    int ans = 1e9+7;

    vector<int> dist(N, -1);
    queue<int> bfs;

    dist[start] = 0;
    bfs.push(start);

    while (!bfs.empty()) {
        int node = bfs.front();
        bfs.pop();

        for (int adj_node : adj[node]) {
            if (dist[adj_node] == -1) {
                dist[adj_node] = dist[node] + 1;
                bfs.push(adj_node);
            } else if (dist[adj_node] >= dist[node]) {
                ans = min(ans, 1 + dist[adj_node] + dist[node]);
            }
        }
    }

    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>M;
    adj.resize(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ans = 1e9+7;
    for (int i = 0; i < N; i++) { ans = min(ans, cycle_len(i)); }

    if (ans == 1e9+7) {
        cout << -1 << endl;
        return 0;
    }

    cout << ans << endl;
}
