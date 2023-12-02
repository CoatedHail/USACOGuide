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
    long long n;
    cin >> n;
    long long ans =0;
    for(long long i = 2; i*i<=n; i++)
    {
        long long numex = 0;
        while(n%i==0)
        {
            numex++;
            n = n/i;
        }
        for(long long j = 1; numex-j>=0; j++)
        {
            ans++;
            numex-=j;
        }
    }
    if(n>1)
        ans++;
    cout<<ans;
}
