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

int dfs(int node, int parent, vector<int> &changed_to, const vector<vector<int>> &adj) {
    int length_added = 0;

    for (int child : adj[node]) {
        if (child == parent) { continue; }
        length_added += dfs(child, node, changed_to, adj);
    }


    if (parent >= 0 && changed_to[node] == node) {
        changed_to[node] = changed_to[parent];
        changed_to[parent] = node;
        length_added += 2;
    } else if (parent < 0 && changed_to[node] == node) {
        /*
         * If the current node is the root and did not swap its position yet,
         * swap it with any of its children.
         */
        changed_to[node] = changed_to[adj[node][0]];
        changed_to[adj[node][0]] = node;
        length_added += 2;
    }

    return length_added;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    cin>>n;
    vector<vector<int>> adj(n+1);
    vector<int> changed(n+1);
    for(int i = 1; i<n; i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        changed[i]=i;
    }
    changed[n]=n;
    int totallen = dfs(1,-1,changed,adj);
    cout<<totallen<<endl;
    for(int i = 1; i<changed.size(); i++)
        cout<<changed[i]<<" ";
}