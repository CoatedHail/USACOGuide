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
    int num=0;
    string S;
    cin>>S;
    int pow = 1;
    vector<long long> v(2019,0);
    v[0]=1;
    long long ans = 0;
    for(int i = S.size()-1; i>=0; i--)
    {
        num = (num + pow * (S[i] - '0')) % 2019;
        v[num]++;
        pow = pow*10%2019;
    }
    for(int i = 0; i<2019; i++)
    {
        ans+=v[i]*(v[i]-1)/2;
    }
    cout<<ans;
}
