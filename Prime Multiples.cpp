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
    cin>>n>>k;
    vector<long long> v(k);
    for(int i = 0; i<k; i++)
    {
        cin>>v[i];
    }
    long long ans = 0;
    for(long long i = 1; i<1<<k; i++)
    {
        long long prime=1;
        for(long long j = 0; j<k; j++)
        {
            if(i&(1<<j))
            {
                if(prime>n/v[j])
                {
                    prime = n+1;
                    break;
                }
                prime*=v[j];
            }
        }
        if(__builtin_popcount(i)%2)
            ans+=n/prime;
        else
            ans-=n/prime;
    }
    cout<<ans;

}