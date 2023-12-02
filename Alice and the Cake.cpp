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
    while(t--)
    {
        long long n;
        cin>>n;
        vector<long long> v(n);
        long long sum = 0;
        for(int i =0; i<n; i++) {
            cin >> v[i];
            sum+=v[i];
        }
        multiset<long long> p = {sum};
        multiset<long long> q(v.begin(),v.end());
        while(!p.empty())
        {
            long long x = *--p.end();
            if(x<*--q.end()) break;
            p.erase(--p.end());
            if(q.find(x)!=q.end())
                q.erase(q.find(x));
            else
            {
                p.insert(x/2);
                p.insert((x+1)/2);
            }
        }
        if(q.empty())
            cout<<"YES";
        else
            cout<<"NO";
        cout<<endl;
    }
}
