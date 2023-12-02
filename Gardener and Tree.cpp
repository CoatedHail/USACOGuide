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
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> adj(n+1);
        vector<int> connects(n+1,0);
        for(int i =1; i<n; i++)
        {
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
            connects[b]++;
            connects[a]++;
        }
        queue<int> deleted;
        vector<int> time(n+1);
        for(int i = 1; i<=n; i++)
        {
            if(connects[i]==1)
            {
                deleted.push(i);
                time[i]=1;
            }
        }

        while(!deleted.empty())
        {
            int curr = deleted.front();
            deleted.pop();
            for(int x:adj[curr])
            {
                if(connects[x]!=1)
                {
                    connects[x]--;
                    if(connects[x]==1) {
                        time[x] = time[curr] + 1;
                        deleted.push(x);
                    }
                }
            }
        }
        int ans =0;
        for(int i =1; i<=n; i++)
        {
            if(time[i]<=k)
                ans++;
        }
        cout<<n-ans<<endl;
    }
}
