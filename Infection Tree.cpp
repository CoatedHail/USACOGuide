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

long long n;
vector<int> children,dp;
vector<vector<int>> adj;
void child(int node,int parent)
{
    dp[node]=0;
    int sum = 0;
    for(auto x: adj[node])
    {
        if(x!=parent)
        {
            child(x,node);
            sum+=dp[x];
            children[node]+=children[x];
        }
    }
    for(auto x: adj[node])
    {
        if(x!=parent)
        {
            dp[node]=max(dp[node], sum-dp[x]+children[x]-1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t;
    cin>>t;
    while(t--) {
        cin>>n;
        adj.clear();
        children.clear();
        dp.clear();
        adj.resize(n);
        for(int i =1 ; i<n; i++)
        {
            int a,b;
            cin>>a>>b;
            a--;
            b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        children.resize(n,1);
        dp.resize(n);
        child(0,-1);
        cout<<dp[0]<<endl;
    }
}
