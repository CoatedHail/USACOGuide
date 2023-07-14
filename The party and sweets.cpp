
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> b(n), g(m);
    long long res = 0;

    for (int i = 0; i < n; i++) {
        cin >> b[i];
        res += b[i];
    }

    for (int i = 0; i < m; i++) { cin >> g[i]; }
    res *= m;

    sort(b.begin(), b.end());
    sort(g.begin(), g.end());

    if (b[n - 1] > g[0]) {
        cout << -1;
        return 0;
    }

    for (int i = 1; i < m; i++) { res += g[i] - b[n - 1]; }

    if (g[0] != b[n - 1]) { res += g[0] - b[n - 2]; }

    cout << res << endl;
}