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
    while(t--)
    {
        int n;
        cin>>n;
        vector<char> s(n);
        int count = 0;
        for(int i = 0; i<n; i++)
        {
            cin>>s[i];
            if(s[i]=='*')
                count++;
        }
        int pos=-1;
        int cur = -1;
        for(int i = 0; i<n; i++)
        {
            if(s[i]=='*')
            {
                cur++;
                if(cur==count/2)
                    pos=i;
            }
        }
        long long ans = 0;
        cur = pos-count/2;
        for(int i = 0; i<n; i++)
        {
            if(s[i]=='*')
            {
                ans+=abs(cur-i);
                cur++;
            }
        }
        cout<<ans<<endl;
    }
}
