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
        vector<vector<int>> adj(n+1);
        for(int i =1; i<=n; i++)
        {
            string row;
            cin>>row;
            for(int j = 1; j<=n; j++)
            {
                if(row[j-1]=='1')
                    adj[j].push_back(i);
            }
        }
        vector<set<int>> values(n+1);
        int currval = 1;
        int findset = 0;
        while(currval!=n+1)
        {
            for(int i = 1;i<=n; i++) {
                if (adj[i].size() == findset)
                    values[i].insert(currval++);
                for (int s: adj[i])
                    values[i].insert(values[s].begin(), values[s].end());
            }
            findset++;
        }
        for(int i = 1; i<=n; i++)
        {
            cout<<values[i].size()<<" ";
            for(int val :values[i])
                cout<<val<<" ";
            cout<<endl;
        }
    }
}
