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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n,k;
    long long ans = 0;;
    cin>>n;
    vector<int> v(20,0);
    for(int i = 0; i<n; i++)
    {
        cin>>k;
        for(int j = 0; j<20; j++)
        {
            v[j]+=(k&1);
            k>>=1;
        }
    }
    for(int j= 0; j<n; j++)
    {
        long long l = 0;
        for(int i = 0; i<20; i++)
        {
            if(v[i]!=0)
            {
                l+=(1<<i);
                v[i]--;
            }
        }
        ans+=l*l;
    }
    cout<<ans;
}