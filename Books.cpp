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
    int n,t;
    cin>>n>>t;
    vector<long long> v;
    for(int i =0; i<n; i++)
    {
        int num;
        cin>>num;
        v.push_back(num);
    }
    long long ans = 0;
    long long time = v[0];
    long long books = 1;
    long long left = 0, right = 0;
    while (right < n) {
        if (time <= t) {
            books++;
            right++;
            time += v[right];
        } else {
            books--;
            ans = max(ans, books);
            time -= v[left];
            left++;
        }
    }
    ans = max(ans, books - 1);

    cout << ans << endl;

}
