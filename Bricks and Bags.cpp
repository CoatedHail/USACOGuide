#include <iostream>
#include <math.h>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cstdio>

using namespace std;

const int mod = 1e9+7;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n+1);
        for(int i =0 ; i<n; i++)
            cin>>a[i+1];
        sort(a.begin(),a.end());
        int ans = 0;
        for(int i = 3; i<n; i++)
        {
            ans = max(ans,(a[i]-a[i-1])+(a[i]-a[1]));
            ans = max(ans, (a[i+1]-a[i])+(a[n]-a[i]));
        }
        ans = max(ans,(a[n]-a[n-1])+(a[n]-a[1]));
        for(int i = 1; i<3; i++)
            ans = max(ans, (a[i+1]-a[i])+(a[n]-a[i]));
        cout<<ans<<endl;
    }
}
