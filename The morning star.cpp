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
    while(t--)
    {
        int n;
        cin>>n;
        map<int,int> up,side, diag1,diag2;
        long long ans = 0;
        for(int i = 0; i<n; i++)
        {
            int x,y;
            cin>>x>>y;
            up[x]++;
            side[y]++;
            diag1[x-y]++;
            diag2[x+y]++;
        }
        for(auto x: up)
            ans+=x.second*(x.second-1);
        for(auto x: side)
            ans+=x.second*(x.second-1);
        for(auto x: diag1)
            ans+=x.second*(x.second-1);
        for(auto x: diag2)
            ans+=x.second*(x.second-1);
        cout<<ans<<endl;
    }
}
