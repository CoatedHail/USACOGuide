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

int n;
vector<long long> haybales,subtr;
long long tot = 0;
long long each;

vector<vector<int>> adj;
vector<tuple<int,int,long long>> orders;
void subtree(int node, int p)
{
    subtr[node]=haybales[node];
    for(int child: adj[node])
    {
        if(child!=p)
        {
            subtree(child,node);
            subtr[node]+=subtr[child];
        }
    }
}
void order(int node, int p)
{
    for(int child:adj[node])
    {
        if(child!=p)
        {
            if(subtr[child]>=0) order(child,node);
            if(subtr[child]>0)
                orders.push_back({child,node,subtr[child]});
        }
    }
    for(int child:adj[node])
    {
        if(child!=p&&subtr[child]<0)
        {
            orders.push_back({node,child,-subtr[child]});
            order(child,node);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    haybales.resize(n+1,0);
    adj.resize(n+1);
    for(int i = 1; i<=n; i++){
        cin>>haybales[i];
        tot+=haybales[i];
    }
    each = tot/n;
    for(int i= 1; i<=n; i++)
        haybales[i]-=each;
    subtr.resize(n+1,0);
    for(int i = 1; i<n; i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    subtree(1,-1);
    order(1,-1);
    cout<<orders.size()<<endl;
    for(auto x:orders)
        cout<<get<0>(x)<<" "<<get<1>(x)<<" "<<get<2>(x)<<endl;
}
