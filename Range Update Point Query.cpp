#include <iostream>
#include <math.h>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <set>
#include <unordered_map>
#include <iomanip>
#include <cstdio>

using namespace std;

const int mod = 1e9+7;

int digitsum(int n)
{
    int ret = 0;
    while(n)
    {
        ret+=n%10;
        n/=10;
    }
    return ret;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long t;
    cin>>t;
    while(t--)
    {
        long long n,q;
        cin>>n>>q;
        set<int> s;
        vector<int> a(n);
        for(int i =0; i<n; i++) {
            cin >> a[i];
            if(a[i]>9)
                s.insert(i);
        }
        while(q--)
        {
            int type;
            cin>>type;
            if(type==1)
            {
                int l,r;
                cin>>l>>r;
                l--;
                r--;
                int lst = l;
                while(!s.empty())
                {
                    auto it = s.lower_bound(lst);
                    if(it==s.end()||*it>r) break;
                    a[*it]=digitsum(a[*it]);
                    int paiu = *it;
                    s.erase(it);
                    if(a[paiu]>9)
                        s.insert(paiu);
                    lst = paiu+1;
                }
            }
            else
            {
                int x;
                cin>>x;
                x--;
                cout<<a[x]<<endl;
            }
        }
    }
}
