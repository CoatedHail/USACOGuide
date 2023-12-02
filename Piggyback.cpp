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

unordered_map<int, vector<int>> mp;
vector<vector<int>> dist;

void distance(int s, int ix) {
    queue<pair<int, int>> q;
    q.push({s, 0});
    dist[ix][s] = 0;
    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        for (int n : mp[p.first]) {
            if (dist[ix][n] != -1) { continue; }
            dist[ix][n] = p.second + 1;
            q.push({n, dist[ix][n]});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("piggyback.in", "r", stdin);
    freopen("piggyback.out", "w", stdout);
    int B, E, P, N, M;
    cin >> B >> E >> P >> N >> M;
    dist.resize(4,vector<int>(N+1,-1));
    for(int i =0; i<M; i++)
    {
        int a,b;
        cin>>a>>b;
        mp[--a].push_back(--b);
        mp[b].push_back(a);
    }
    distance(0, 0);
    distance(1, 1);
    distance(N - 1, 2);
    int mine = INT32_MAX;
    for (int i = 0; i < N; i++) {
        int energy = dist[0][i] * B + dist[1][i] * E + dist[2][i] * P;
        mine = min(mine, energy);
    }
    cout << mine << endl;
}
