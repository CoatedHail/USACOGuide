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
    vector<long long> heights(N);
    for(int i = 0; i<N; i++)
    {
        cin>>heights[i];
    }
    stack<long long> stck;
    vector<long long> area(N, 0);
    for (long long i = 0; i < N; i++) {
        while (stck.size() && heights[stck.top()] >= heights[i]) stck.pop();
        int width = i - (stck.size() ? stck.top() : -1);
        area[i] += width * heights[i];
        stck.push(i);
    }
    while (stck.size()) stck.pop();
    for (long long i = N - 1; ~i; i--) {
        while (stck.size() && heights[stck.top()] >= heights[i]) stck.pop();
        int width = (stck.size() ? stck.top() : N) - i;
        area[i] += (width - 1) * heights[i];
        stck.push(i);
    }
    cout<< *max_element(area.begin(), area.end());
}
