#include <iostream>
#include <math.h>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <cstdio>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    priority_queue<long long, vector<long long>, greater<long long> > pq;
    long long S = 0;

    for(int i = 1;i <= n;i++){
        long long x; cin >> x;
        S += x;
        pq.push(x);

        while(S < 0){
            S -= pq.top();
            pq.pop();
        }
    }

    cout << (int) pq.size();

}
