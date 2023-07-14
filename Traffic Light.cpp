
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
    int x,n;
    cin>>x>>n;
    set<int> lights{0,x};
    multiset<int> distance{x};
    for(int i = 0; i<n; i++)
    {
        int pos;
        cin>>pos;
        auto it1 = lights.upper_bound(pos);
        auto it2 = it1;
        --it2;
        distance.erase(distance.find(*it1 - *it2));
        distance.insert(pos-*it2);
        distance.insert(*it1-pos);
        lights.insert(pos);

        auto ans = distance.end();
        --ans;
        cout<<*ans<<" ";
    }
}
