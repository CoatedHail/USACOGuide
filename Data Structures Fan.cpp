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
    while(t--) {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i =0; i<n; i++)
            cin>>a[i];
        string s;
        cin>>s;
        vector<int> ans(2,0);
        vector<int> pref(n+1,0);
        for(int i = 1; i<n+1; i++)
        {
            ans[s[i-1]-'0']^=a[i-1];
            pref[i]=pref[i-1]^a[i-1];
        }
        int massxor = 0;
        int q;
        cin>>q;
        for(int i =0; i<q; i++)
        {
            int type;
            cin>>type;
            if(type==1)
            {
                int l,r;
                cin>>l>>r;
                massxor^=pref[r]^pref[l-1];
            }
            else
            {
                int g;
                cin>>g;
                cout<<(massxor^ans[g])<<" ";
            }
        }
        cout<<endl;
    }
}
