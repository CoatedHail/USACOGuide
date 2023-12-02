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
    int n, k;
    cin >> n >> k;
    vector<long long> v(n + 1), tw(n + 1), fi(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for (int i = 1; i <= n; i++) {
        int two, five;
        two = five = 0;
        while (v[i] % 2 == 0) {
            two++;
            v[i] /= 2;
        }
        while (v[i] % 5 == 0) {
            five++;
            v[i] /= 5;
        }
        tw[i] = two;
        fi[i] = five;
    }
    vector<vector<long long>> pre(n + 1, vector<long long>(6001, -1)), curr(n + 1, vector<long long>(6001, -1));
    pre[0][0] = 0;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            for (int l = 0; l <= 6000; l++) {
                if (fi[i] <= l && j != 0) {
                    if (pre[j - 1][l - fi[i]] != -1)
                        curr[j][l] = max(curr[j][l], pre[j - 1][l - fi[i]] + tw[i]);
                }
                if (pre[j][l] != -1) {
                    curr[j][l] = max(curr[j][l], pre[j][l]);
                }
            }
        }
        for (int j = 0; j <= k; j++) {
            for (int l = 0; l <= 6000; l++) {
                pre[j][l] = curr[j][l];
                curr[j][l] = -1;
            }
        }
    }
    for (long long i = 0; i <= 6000; i++)
    {
        ans = max(ans,min(i,pre[k][i]));
    }
    cout<<ans;
}
