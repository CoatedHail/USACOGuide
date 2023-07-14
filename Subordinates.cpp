#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"
#include "set"
#include "unordered_set"
#include "stack"
#include "map"
#include "limits.h"
#include "cstdio"
#include "math.h"
#include <iomanip>
#include <numeric>
using namespace std;

int n;
vector<vector<int>> adj;
vector<int> subs;
void sub(int x)
{
    subs[x]=1;
    for(int child : adj[x])
    {
        sub(child);
        subs[x]+=subs[child];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    adj.resize(n+1);
    subs.resize(n+1,0);
    for(int i = 2; i<=n; i++)
    {
        int num;
        cin>>num;
        adj[num].push_back(i);
    }
    sub(1);
    for(int i = 1; i<=n; i++)
    {
        cout<<subs[i]-1<<" ";
    }
}

