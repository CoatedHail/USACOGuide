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
        long long n;
        cin>>n;
        vector<long long> v(n,0);
        for(int i = 0; i<n; i++)
            cin>>v[i];
        sort(v.begin(),v.end());
        if(v[1]==v[n])
        {
            cout<<n/2<<endl;
            continue;
        }
        long long ans = 0;
        for(long long i = 1; i<n; i++)
        {
            if(v[i]!=v[i-1])
                ans = max(ans,i*(n-i));
        }
        cout<<ans<<endl;
    }
}
