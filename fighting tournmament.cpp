#include <iostream>
#include <math.h>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>
#include <cstdio>

using namespace std;

const int mod = 1e9+7;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long q;
    cin>>q;
    while(q--)
    {
        long long n,t;
        cin>>n>>t;
        vector<long long> a(n);
        for(int i =0; i<n; i++) {
            cin >> a[i];
        }
        vector<vector<long long>> wins(n+1);
        long long first = 0;
        long long second = 1;
        for(long long i =1; i<n; i++)
        {
            long long f = a[first];
            long long s = a[second];
            if(f>s) {
                wins[f].push_back(i);
                second++;
            }
            else{
                wins[s].push_back(i);
                first = second;
                second++;

            }
        }
        while(t--)
        {
            long long part,round;
            cin>>part>>round;
            part--;
            long long ans = 0;
            if(round<n)
            {
                for(auto x: wins[a[part]])
                    if(x<=round)
                        ans++;
            }
            else
            {
                ans = wins[a[part]].size();
                if(a[part] ==n)
                    ans+=round-n+1;
            }
            cout<<ans<<endl;
        }
    }
}
