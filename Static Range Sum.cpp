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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,Q;
    vector<long long> v;
    cin>>N>>Q;
    v.push_back(0);
    for(int i = 0; i<N; i++)
    {
        int num;
        cin>>num;
        v.push_back(num);
    }
    for(int i = 1; i<N+1; i++)
    {
        v[i]+=v[i-1];
    }
    for(int i = 0; i<Q; i++)
    {
        int a,b;
        cin>>a>>b;
        cout<<v[b]-v[a]<<endl;
    }
}
