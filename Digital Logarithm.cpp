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
        int n;
        cin>>n;
        vector<int> a(n),b(n);
        for(int i =0; i<n; i++)
            cin>>a[i];
        for(int i =0; i<n; i++)
            cin>>b[i];
        priority_queue<int> pa(a.begin(),a.end()),pb(b.begin(),b.end());
        int ans = 0;
        while(!pa.empty())
        {
            if(pa.top()==pb.top())
            {
                pa.pop();
                pb.pop();
                continue;
            }
            ans++;
            if(pa.top()>pb.top())
            {
                pa.push(to_string(pa.top()).size());
                pa.pop();
            }
            else
            {
                pb.push(to_string(pb.top()).size());
                pb.pop();
            }
        }
        cout<<ans<<endl;
    }

}
