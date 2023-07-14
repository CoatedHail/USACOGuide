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
    int T;
    cin>>T;
    for(int i = 0; i<T; i++)
    {
        int num;
        cin>>num;
        vector<long long> v(num+1,0);
        vector<long long> count(num*10+1,-1);
        count[num]=0;
        string s;
        cin>>s;
        long long ans = 0;
        for(int j = 0; j<num; j++)
        {
            v[j+1]=(s[j]-'0') -1;
        }
        for(int j = 1; j<num+1; j++)
        {
            v[j]+=v[j-1];
        }
        for(int j = 1; j<num+1; j++)
        {
            count[v[j]+num]++;
            ans+=count[v[j]+num];
        }
        cout<<ans<<endl;
    }
}
