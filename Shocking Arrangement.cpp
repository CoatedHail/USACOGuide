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
        long long n;
        cin>>n;
        vector<long long> positive;
        vector<long long> negative;
        long long pref = 0;
        long long maxs=0;
        for(int i = 0; i<n; i++) {
            long long x;
            cin>>x;
            maxs = max(maxs,x);
            if(x<0)
                negative.push_back(x);
            else
                positive.push_back(x);
        }
        if(maxs == 0) {
            cout << "NO" << endl;
            continue;
        }
        else
            cout<<"YES"<<endl;
        vector<long long> ans;
        for(int i = 0; i<n; i++)
        {
            if(pref<=0)
            {
                if(positive.size()>0) {
                    ans.push_back(positive[0]);
                    positive.erase(positive.begin());
                }
                else
                {
                    ans.push_back(negative[0]);
                    negative.erase(negative.begin());
                }
            }
            else
            {
                if(negative.size()>0) {
                    ans.push_back(negative[0]);
                    negative.erase(negative.begin());
                }
                else
                {
                    ans.push_back(positive[0]);
                    positive.erase(positive.begin());
                }
            }
            pref+=ans[i];
        }
        for(auto x: ans)
            cout<<x<<" ";
        cout<<endl;
    }
}
