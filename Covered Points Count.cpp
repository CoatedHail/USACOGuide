
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
    int n;
    cin>>n;
    set<long long> points;
    map<long long, int> freq;
    for (int i = 0; i < n; i++) {
        long long l, r;
        cin >> l >> r;
        freq[l]++;
        freq[r + 1]--;
        points.insert(l);
        points.insert(r + 1);
    }

    int layers = freq[*points.begin()];
    auto it = next(points.begin());
    vector<long long> covered_num(n + 1);

    while (it != points.end()) {
        covered_num[layers] += (*it - *prev(it));
        layers += freq[*it];
        it++;
    }

    for (int i = 1; i < n; i++) { cout << covered_num[i] << " "; }
    cout << covered_num[n] << endl;
}
