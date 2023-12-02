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
        string a,b;
        cin>>a>>b;
        bool ok = true;
        for(int i = 0; i<n; i++)
        {
            if(a[i]!='1'-b[i]+'0')
            {
                ok = false;
                break;
            }
        }
        if(a==b)
            ok = true;
        if(ok == false)
        {
            cout<<"NO"<<endl;
            continue;
        }
        vector<pair<int,int>> ops;
        if(a[0]!=b[0])
        {
            ops.push_back({1,n});
            a=b;
        }
        vector<int> cnt(n+1);
        for(int i = 0; i<n; i++)
        {
            if(a[i]=='1')
            {
                if(i == 0)
                {
                    ops.push_back({1,n});
                    ops.push_back({2,n});
                }
                else
                {
                    cnt[i]++;
                    cnt[i+1]++;
                }
            }
        }
        for(int i = 0; i<n; i++)
        {
            if(cnt[i+1]%2==1)
            {
                ops.push_back({1,i+1});
            }
        }
        cout<<"YES"<<endl;
        cout<<ops.size()<<endl;
        for(auto i: ops)
        {
            cout<<i.first<<" "<<i.second<<endl;
        }
    }
}
