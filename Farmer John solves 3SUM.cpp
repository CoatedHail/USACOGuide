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


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("threesum.in", "r", stdin);
    //freopen("threesum.out", "w", stdout);
    int n,q;
    cin>>n>>q;
    vector<int> val(n);
    for(int i =0 ; i<n; i++)
    {
        cin>>val[i];
        val[i]+=1e6;
    }
    vector<vector<long long>> ways(n, vector<long long>(n, 0));
    vector<int> frq(2 * 1e6);
    for (int i = n - 2; i >= 0; i--) {
        frq[val[i + 1]]++;
        for (int j = i + 2; j < n; j++) {
            int compliment = (1e6 * 3) - (val[i] + val[j]);

            if (compliment >= 0 && compliment < (2 * 1e6)) {
                ways[i][j] = frq[compliment];
            }
            frq[val[j]]++;
        }

        for (int j = i + 1; j < n; j++) { frq[val[j]]--; }
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            ways[i][j] +=
                    (ways[i + 1][j] + ways[i][j - 1] - ways[i + 1][j - 1]);
        }
    }

    for (int _ = 0; _ < q; _++) {
        int l, r;
        cin >> l >> r;
        cout << ways[l - 1][r - 1] << '\n';
    }
}
