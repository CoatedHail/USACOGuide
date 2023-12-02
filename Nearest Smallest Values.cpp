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
    int N;
    cin >> N;
    stack<pair<int, int>> stack;
    stack.push({0, 0});

    for (int i = 1; i <= N; ++i) {
        int a;
        cin >> a;
        while (!stack.empty() && stack.top().first >= a) stack.pop();
        cout << stack.top().second << " ";
        stack.push({a, i});
    }
}
