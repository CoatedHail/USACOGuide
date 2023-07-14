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
    int N, X;
    cin>>N>>X;
    vector<int> v;
    v.push_back(0);
    for(int i = 0; i<N; i++)
    {
        int num;
        cin>>num;
        v.push_back(v[i]+num);
    }
    int count = 0;
    for(int i = 1; i<N+1; i++)
    {
        for(int j = 0; j<i; j++)
        {
            if(v[i]-v[j]==X)
            {
                count++;
            }
        }
    }
    cout<<count;
}
