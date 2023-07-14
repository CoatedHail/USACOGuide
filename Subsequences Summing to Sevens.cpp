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
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin>>N;
    vector<long long> v;
    v.push_back(0);
    for(int i =0; i<N; i++)
    {
        int num;
        cin>>num;
        v.push_back(v[i]+num);
    }
    int biggest = 0;
    for(int i = N; i>=1; i--)
    {
        for(int j = 0; j<i-biggest; j++)
        {
            if((v[i]-v[j])%7 == 0&&(i-j)>biggest)
            {
                biggest = i-j;
                break;
            }
        }
    }
    cout<<biggest;
}
