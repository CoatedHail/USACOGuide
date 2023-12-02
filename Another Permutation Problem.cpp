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
        int n;
        cin>>n;
        int ans = 0;
        vector<int> pr(n*n,-1);
        for(int i = 1; i<=n; i++)
        {
            for(int j = 1; j<=n; j++)
                pr[i*j-1]=1;
        }
        for(int i = n*n; i>=1; i--)
        {
            if(pr[i-1]==-1)
                continue;
            vector<vector<int>> v(n);
            int curans = -i;
            bool br = false;
            for(int j = n; j>=1; j--)
            {
                int num = min(i/j,n);
                if(num<1)
                {
                    br = true;
                    break;
                }
                v[num-1].push_back(j);
            }
            if(br)
                break;
            stack<int>s;
            for(int j = 0; j<n; j++)
            {
                s.push(j+1);
                bool brk = false;
                for(auto x: v[j])
                {
                    if(s.empty())
                    {
                        brk = true;
                        break;
                    }
                    curans += s.top()*x;
                    s.pop();
                }
                if(brk)
                    break;
            }
            ans = max(ans,curans);
        }
        cout<<ans<<endl;
    }
}
