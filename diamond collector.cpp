
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
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    int n,k;
    cin>>n>>k;
    vector<int> diamonds;
    for(int i = 0; i<n; i++)
    {
        int num;
        cin>>num;
        diamonds.push_back(num);
    }
    vector<int> left(n);
    sort(diamonds.begin(),diamonds.end());
    int l = 0; int r = 0;
    for( ; l<n; l++)
    {
        while (r < n && diamonds[r] - diamonds[l] <= k) r++;
        left[l] = r - l;
    }
    vector<int> maxy(n+1);
    maxy[n]=0;
    for (int i = n - 1; i >= 0; i--) {
        maxy[i] = max(maxy[i + 1], left[i]);
    }
    int ans = 0;
    for (int l = 0; l < n; l++) {
        ans = max(ans, left[l] + maxy[l + left[l]]);
    }
    cout << ans << endl;
}
