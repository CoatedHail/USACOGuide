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

vector<vector<int>> conj;
int n,k,v,u;
vector<int> depth,sizes,det;
long long ans = 0;
int cmp(int a, int b)
{
    return a>b;
}
int dfs(int u,int f)
{
    depth[u]=depth[f]+1;
    sizes[u]=1;
    for(int i = 0; i<conj[u].size(); i++)
    {
        if((v=conj[u][i])==f)
            continue;
        sizes[u]+=dfs(v,u);
    }
    det[u]=sizes[u]-depth[u];
    return sizes[u];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    conj.resize(n+1);
    depth.resize(n+1,0);
    sizes.resize(n+1,0);
    det.resize(n+1);
    for(int i = 1; i<n; i++)
    {
        cin>>u>>v;
        conj[u].push_back(v);
        conj[v].push_back(u);
    }
    dfs(1,0);
    nth_element(det.begin()+1,det.begin()+n-k,det.end(),cmp);
    for(int i =1; i<=n-k; i++)
        ans+=det[i];
    cout<<ans;

}
