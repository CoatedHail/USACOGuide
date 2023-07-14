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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin>>N;
    vector<long long> v;
    v.push_back(0);
    for(int i = 1; i<=N; i++)
    {
        int num;
        cin>>num;
        v.push_back(v[i-1]+num);

    }
    long long maxsub=v[1];
    long long minsum=0;
    for(int i = 1; i<=N; i++)
    {
        maxsub = max(maxsub,v[i]-minsum);
        minsum = min(minsum, v[i]);
    }
    cout<<maxsub;
}
