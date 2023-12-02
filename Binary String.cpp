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
        string s;
        cin>>s;
        int n = s.size();
        vector<int> prefix(n+1,0);
        for(int i = 1; i<=n; i++)
        {
            prefix[i]=(s[i-1]=='1');
        }
        for(int i = 1; i<=n; i++)
        {
            prefix[i]+=prefix[i-1];
        }
        if(prefix[n]==n||prefix[n]==0)
        {
            cout<<"0"<<endl;
            continue;
        }
        int result = min(prefix[n],n-prefix[n]);
        for(int i = 1; i<=n; i++)
        {
            if(i>=prefix[n])
                result = min(result,(i-prefix[i])-(i-prefix[n]-prefix[i-prefix[n]]));
            else result = min(result, prefix[n]-prefix[i]);
        }
        cout<<result<<endl;
    }
}
