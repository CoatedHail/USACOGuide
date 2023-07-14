
#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"
#include "set"
#include "stack"
#include "map"
#include "limits.h"
#include "cstdio"
#include "math.h"
#include <iomanip>
#include <numeric>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int p = 0; p<t; p++)
    {
        int n;
        cin>>n;
        vector<pair<int,int>> v(n);
        map<int,vector<int>> g;
        set<int> st;
        for(int i = 0; i<n; i++)
        {
            cin>>v[i].first>>v[i].second;
            g[v[i].first].push_back(v[i].second);
            st.insert(v[i].first);
        }
        st.insert(INT_MAX);
        int i = *st.begin();
        priority_queue<int, vector<int>, greater<int>> pq;
        bool fl = true;
        while(i<=1000000000)
        {
            for(auto& x : g[i])
            {
                pq.push(x);
            }
            pq.pop();
            if(pq.empty())
            {
                i = *st.lower_bound(i+1);
            }
            else
            {
                if(pq.top()<=i)
                {
                    fl = false;
                    break;
                }
                i++;
            }
        }
        if(!pq.empty())
        {
            fl = false;
        }
        if(fl ==false)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
}
