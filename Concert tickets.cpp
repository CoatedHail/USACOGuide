
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
    int n,m;
    cin>>n>>m;
    multiset<int> tickets;
    for(int i = 0; i<n; i++)
    {
        int num;
        cin>>num;
        tickets.insert(num);
    }
    int t;
    for (int i = 0; i < m; ++i) {
        cin >> t;
        auto it = tickets.upper_bound(t);
        if (it == tickets.begin()) {
            cout << -1 << "\n";
        } else {
            cout << *(it) << "\n";
            tickets.erase(it);
        }
    }
}
