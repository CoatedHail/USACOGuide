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


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t;
    cin>>t;
    while(t--) {
        long long n;
        cin>>n;
        vector<int> ans(n);
        vector<tuple<int,int,int>> events;
        for(int i = 0; i<n; i++)
        {
            int l,r,a,b;
            cin>>l>>r>>a>>b;
            ans[i]=b;
            events.emplace_back(b,1,i);
            events.emplace_back(l,-1,i);
        }
        int q;
        cin>>q;
        vector<int> query(q);
        for(int i =0; i<q; i++)
        {
            int x;
            cin>>x;
            query[i]=x;
            events.emplace_back(x,0,i);
        }
        sort(events.begin(),events.end());
        reverse(events.begin(),events.end());
        multiset<int>s;
        for(auto x: events)
        {
            if(get<1>(x)==1)
            {
                if(!s.empty())
                {
                    ans[get<2>(x)]=*s.rbegin();
                }
                s.insert(ans[get<2>(x)]);
            }
            else if(get<1>(x)==0)
            {
                if(!s.empty())
                {
                    query[get<2>(x)]=max(query[get<2>(x)],*s.rbegin());
                }
            }
            else {
                auto itr = s.find(ans[get<2>(x)]);
                if(itr!=s.end()){
                    s.erase(itr);
                }
            }
        }
        for(auto x: query)
            cout<<x<<" ";
        cout<<endl;
    }
}
