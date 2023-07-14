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

bool ycompress(pair<int,int> a, pair<int,int> b){
    return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
    int n;
    cin >> n;
    vector<pair<int, int>> times;
    times.push_back(make_pair(0,0));
    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        times.push_back(make_pair(start,end));
    }
    times.push_back(make_pair(INT_MAX, INT_MAX));
    sort(times.begin(), times.end());

    int total = 0;
    int mn = INT_MAX;
    int l_end,r_end,l_far;
    for(int i = 1; i<=n; i++)
    {
        l_end = max(times[i].first, times[i-1].second);
        l_far = max(l_far, l_end);
        r_end = min(times[i].second, times[i + 1].first);
        mn = min(mn, max(0,r_end-l_end));
        total+= max(0, times[i].second-l_far);
    }
    cout<<total-mn;
}
