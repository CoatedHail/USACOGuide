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

const long long MAXN = 5e4;
int n,x[MAXN], y[MAXN],ar[MAXN];

bool cmp(int a, int b)
{
    if(x[a]==x[b]) return y[a]<y[b];
    return x[a]<x[b];
}
bool cmp1(int a, int b)
{
    if(y[a]==y[b]) return x[a]<x[b];
    return y[a]<y[b];
}


int main() {
    freopen("split.in", "r", stdin);
    freopen("split.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    multiset<int> Xlist, Ylist, LeftX, LeftY, RightX, RightY;
    for (int i = 0; i < n; i++) {
        ar[i] = i;
        cin >> x[i] >> y[i];
        Xlist.insert(x[i]);
        Ylist.insert(y[i]);
    }
    sort(ar, ar + n, cmp);
    int x1 = *Xlist.rbegin(), x2 = *Xlist.begin(), y1 = *Ylist.rbegin(), y2 = *Ylist.begin();
    long long area = (x1-x2)*1LL*(y1-y2);
    long long ans = 0;
    for(int k = 0; k<=1; k++) {
        RightX = Xlist;
        RightY = Ylist;
        LeftX.clear();
        LeftY.clear();
        for (int i = 0; i < n; i++) {
            int j = ar[i];
            long long areaL=0, areaR=0;
            LeftX.insert(x[j]);
            LeftY.insert(y[j]);
            RightX.erase(RightX.find(x[j]));
            RightY.erase(RightY.find(y[j]));
            x1 = *LeftX.begin();
            y1 = *LeftY.begin();
            x2 = *LeftX.rbegin();
            y2 = *LeftY.rbegin();
            areaL = (x2 - x1) * 1LL * (y2 - y1);
            if (!RightX.empty()) {
                x1 = *RightX.begin();
                y1 = *RightY.begin();
                x2 = *RightX.rbegin();
                y2 = *RightY.rbegin();
                areaR = (x2 - x1) * 1LL * (y2 - y1);
            }
            ans = max(ans, area - (areaL + areaR));
        }
        sort(ar, ar + n, cmp1);
    }
    cout<<ans;
}
