#include <iostream>
#include <math.h>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <stack>
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
        vector<int> c(n),a(n),b(n);
        for(int i =0 ; i<n; i++)
            cin>>c[i];
        for(int i =0 ; i<n; i++)
            cin>>a[i];
        for(int i =0 ; i<n; i++)
            cin>>b[i];

        long long ans = 0;
        long long len = 0;
        for(int i = 1; i<n; i++)
        {
            long long curr = c[i]+1+abs(a[i]-b[i]);
            if(a[i]!=b[i])
                curr = max(curr, c[i]+1+len-abs(a[i]-b[i]));
            ans = max(ans,curr);
            len = curr;
        }
        cout<<ans<<endl;
    }
}
