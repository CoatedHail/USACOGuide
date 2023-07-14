
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
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> herd(n);
    for (int i = 0; i < n; ++i) { cin >> herd[i]; }
    sort(herd.begin(), herd.end());

    int min_moves = INT32_MAX;
    if (herd[n - 2] - herd[0] == n - 2 && herd[n - 1] - herd[n - 2] > 2) {
        min_moves = 2;
    } else if (herd[n - 1] - herd[1] == n - 2 && herd[1] - herd[0] > 2) {
        min_moves = 2;
    } else {
        int farthest_cow = 0;
        for (int curr_cow = 0; curr_cow < n; ++curr_cow) {
            while (farthest_cow + 1 < n &&
                   herd[farthest_cow + 1] - herd[curr_cow] < n) {
                farthest_cow++;
            }
            min_moves = min(min_moves, n - (farthest_cow - curr_cow + 1));
        }
    }
    int gap_num = 0;
    for (int i = 1; i < n; i++) { gap_num += herd[i] - herd[i - 1] - 1; }
    int max_moves = max(gap_num - (herd[1] - herd[0] - 1),
                        gap_num - (herd[n - 1] - herd[n - 2] - 1));
    cout << min_moves << '\n' << max_moves << endl;
}
