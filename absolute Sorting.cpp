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
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i =0; i<n; i++)
            cin>>v[i];
        int mn = 0, mx = 1e9;
        for(int i = 0; i+1<n; i++)
        {
            int x = v[i];
            int y = v[i+1];
            int midl = (x+y)/2;
            int midr = (x+y+1)/2;
            if(x<y)
                mx = min(mx,midl);
            if(x>y)
                mn = max(mn,midr);
        }
        if(mn<=mx)
            cout<<mn<<endl;
        else
            cout<<-1<<endl;
    }
}
