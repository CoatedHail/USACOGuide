
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
#include <numeric>
using namespace std;

bool cmp(long long a,long long b)
{
    return a>b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("lemonade.in", "r", stdin);
    freopen("lemonade.out", "w", stdout);
    int n;
    cin>>n;
    vector<long long> v;
    for(int i = 0; i<n; i++)
    {
        long long num;
        cin>>num;
        v.push_back(num);
    }
    sort(v.begin(),v.end(),cmp);
    long long ans = 0;
    for(int i =0 ; i<n; i++)
    {
        if(v[i]>=i)
        {
            ans++;
        }
        else
        {
            cout<<ans;
            return 0;
        }
    }
    cout<<ans;
}