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
    long long t;
    cin>>t;
    while(t--)
    {
        long long n,m;
        cin>>n>>m;
        vector<long long> v(n,0);
        for(int i = 0; i<n; i++) {
            cin >> v[i];
        }
        long long ans =0;
        priority_queue<long long> pq;
        priority_queue<long long, vector<long long>, greater<long long>> suf;
        long long curr = 0;
        for(long long i = m-1; i>0; i--)
        {
            curr +=v[i];
            if(v[i]>0)
                pq.push(v[i]);
            while(curr>0)
            {
                ans++;
                curr-=2*pq.top();
                pq.pop();
            }
        }
        curr = 0;
        for(long long i = m; i<n; i++)
        {
            curr+=v[i];
            if(v[i]<0)
                suf.push(v[i]);
            while(curr<0)
            {
                ans++;
                curr-=2*suf.top();
                suf.pop();
            }
        }
        cout<<ans<<endl;
    }
}

