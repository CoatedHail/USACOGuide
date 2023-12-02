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


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t;
    cin>>t;
    while(t--) {
        long long n,k;
        cin>>n>>k;
        vector<long long> s(n+1,0);
        for(int i = 1; i<=n; i++) {
            cin >> s[i];
            s[i]+=s[i-1];
        }
        if(k>=n)
        {
            cout<<s[n]+(k-1+k-n)*n/2<<endl;
        }
        else
        {
            long long maxy = s[k];
            for(long long i = k+1; i<=n; i++)
            {
                maxy = max(maxy,s[i]-s[i-k]);
            }
            cout<<maxy+k*(k-1)/2<<endl;
        }
    }
}
