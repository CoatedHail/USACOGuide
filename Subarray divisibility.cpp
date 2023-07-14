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
    int N;
    cin>>N;
    vector<long long> v;
    v.push_back(0);
    for(int i = 0; i<N; i++)
    {
        int num;
        cin>>num;
        v.push_back(((v[i]+num)%N+N)%N);
    }
    vector<long long> track(N,-1);
    track[0]=0;
    long long count=0;
    for(int i = 1; i<N+1; i++)
    {
        track[v[i]]++;
        count+=track[v[i]];
    }
    cout<<count;
}
