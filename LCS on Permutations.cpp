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
#include <numeric>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> lis;
    vector<int> a(n+1),b(n+1),c(n+1),pos(n+1);
    for(int i = 1; i<=n; i++)
    {
        cin>>a[i];
        pos[a[i]]=i;
    }
    for(int i = 1; i<=n; i++)
        cin>>b[i];
    for(int i = 1; i<=n; i++)
    {
        c[i]=pos[b[i]];
    }
    for(int i = 1; i<=n; i++)
    {
        int p = lower_bound(lis.begin(),lis.end(),c[i])-lis.begin();
        if(p == lis.size())
        {
            lis.push_back(c[i]);
        }
        else
            lis[p]=c[i];
    }
    cout<<lis.size();
}
