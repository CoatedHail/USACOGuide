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
        int n,m;
        cin>>n>>m;
        vector<int> v(n+1,0);
        vector<int> a(m);
        for(int i =0; i<m; i++)
        {
            cin>>a[i];
            v[a[i]]++;
        }
        int l = 0;
        int r= m*2;
        int ans = 0;
        while(l<=r)
        {
            int mid = (l+r)/2;
            long long fr = 0, need = 0;
            for(int i = 0; i<n; i++)
            {
                if(mid>=v[i+1])
                {
                    fr+=(mid-v[i+1])/2;
                }
                else
                    need+=v[i+1]-mid;
            }
            if(need<=fr)
            {
                ans = mid;
                r = mid-1;
            }
            else
                l = mid+1;
        }
        cout<<ans<<endl;
    }
}
