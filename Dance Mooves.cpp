#include <iostream>
#include <math.h>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cstdio>

using namespace std;

int N,K;
vector<int> A,B,P,from,cnt;
vector<vector<int>> S;
int uniquepos;

void add(int node)
{
    for(int x : S[node])
    {
        if(cnt[x]==0)
            uniquepos++;
        cnt[x]++;
    }
}
void remove(int node)
{
    for(int x:S[node])
    {
        if(cnt[x]==1)
            uniquepos--;
        cnt[x]--;
    }
}
vector<bool> vis;
queue<int> q;
void dfs(int node)
{
    vis[node]=true;
    add(node);
    q.push(node);
    if(!vis[P[node]])
        dfs(P[node]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>K;
    A.resize(K+1);
    B.resize(K+1);
    P.resize(N+1);
    S.resize(N+1);
    from.resize(N+1);
    cnt.resize(N+1);
    vis.resize(N+1);
    for(int i = 0; i<K; i++)
    {
        cin>>A[i]>>B[i];
    }
    for(int i = 1; i<=N; i++)
    {
        from[i]=i;
        S[i].push_back(i);
    }
    for(int i = 0; i<K; i++)
    {
        S[from[A[i]]].push_back(B[i]);
        S[from[B[i]]].push_back(A[i]);
        swap(from[A[i]],from[B[i]]);
    }
    for(int i = 1; i<=N; i++)
        P[from[i]]=i;
    vector<int> ans(N+1);
    for(int i = 1; i<=N; i++)
    {
        if(!vis[i])
        {
            dfs(i);
            int tempans = uniquepos;
            while(!q.empty())
            {
                remove(q.front());
                ans[q.front()]=tempans;
                q.pop();
            }
        }
    }
    for(int i = 1; i<=N; i++)
        cout<<ans[i]<<endl;
}
