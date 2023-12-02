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
    int n;
    cin >> n;
    for (int q = 0; q < n; q++) {
        int x;
        int div_num = 0;
        cin >> x;
        for (int i = 1; i * i <= x; i++) {
            if (x % i == 0) { div_num += i * i == x ? 1 : 2; }
        }
        cout << div_num << '\n';
    }
}