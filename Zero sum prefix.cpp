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


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        long long n;
        cin>>n;
        vector<long long> v(n+1);
        map<long long,long long> freq;
        long long maxfr = 0, currsum = 0, ans = 0;
        bool found= 0;
        for(long long i = 0; i<n; i++) {
            cin >> v[i];
            if (v[i] == 0) {
                if (found)
                    ans += maxfr;
                else
                    ans += freq[0];
                found = true;
                maxfr = 0;
                freq.clear();
            }
            currsum += v[i];
            maxfr = max(maxfr,++freq[currsum]);
        }
        if(found)
            ans+=maxfr;
        else
            ans+=freq[0];
        cout<<ans<<endl;
    }
}
