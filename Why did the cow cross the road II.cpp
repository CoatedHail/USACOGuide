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
    freopen("maxcross.in", "r", stdin);
    freopen("maxcross.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,K,B;
    cin>>N>>K>>B;
    vector<int> v(N+1,1);
    v[0]=0;
    for(int i =0; i<B; i++)
    {
        int num;
        cin>>num;
        v[num]=0;
    }
    for(int i = 1; i<N+1; i++)
    {
        v[i]+=v[i-1];
    }
    int minimum = INT_MAX;

    for(int i = K; i<N+1; i++)
    {
        int a = v[i]-v[i-K];
        if(K-a<minimum)
            minimum=K-a;
    }
    cout<<minimum;
}
