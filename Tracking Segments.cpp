#include <iostream>
#include <math.h>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <queue>
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
        long long n,m;
        cin >> n>>m;
        vector<pair<int,int>> segments;
        for(int i = 0; i<m; i++)
        {
            int a,b;
            cin>>a>>b;
            a--;
            segments.push_back({a,b});
        }
        int q;
        cin>>q;
        vector<int> ord (q,0);
        for(int i = 0; i<q; i++)
        {
            int num;
            cin>>num;
            ord[i]=num-1;
        }
        int l = 0;
        int r = q+1;
        while(r-l>1)
        {
            int mid = (l+r)/2;
            vector<int> curr(n,0);
            for(int i = 0; i<mid; i++)
            {
                curr[ord[i]]=1;
            }
            vector<int> pr(n+1,0);
            for(int i = 0; i<n; i++)
            {
                pr[i+1]=pr[i]+curr[i];
            }
            bool ok = false;
            for(auto i : segments)
            {
                if(pr[i.second]-pr[i.first]>(i.second-i.first)/2)
                {
                    ok = true;
                    break;
                }
            }
            if(ok)
            {
                r = mid;
            }
            else
                l = mid;
        }
        if(r == q+1)
            r = -1;
        cout<<r<<endl;
    }
}
