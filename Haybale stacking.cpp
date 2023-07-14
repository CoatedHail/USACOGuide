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
using namespace std;


int main()
{
    freopen("stacking.in", "r", stdin);
    freopen("stacking.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,K;
    cin>>N>>K;
    vector<int> v(N+1,0);
    for(int i = 0; i<K; i++)
    {
        int a,b;
        cin>>a>>b;
        v[a]++;
        v[b+1]--;
    }
    for(int i = 1; i<N+1; i++)
    {
        v[i]+=v[i-1];
    }
    sort(v.begin(),v.end());
    cout<<v[(N+1)/2];
}
