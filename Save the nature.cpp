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

long long x,a,y,b;
long long k;
vector<long long> tickets;

bool works(int sell)
{
    vector<long long> percentage(sell,0);
    for(int i = a-1; i<sell; i+=a)
    {
        percentage[i]+=x;
    }
    for(int i = b-1; i<sell; i+=b)
    {
        percentage[i]+=y;
    }
    sort(percentage.begin(),percentage.end(),greater<long long>());
    long long curr = 0;
    for(int i = 0; i<sell; i++)
    {
        curr+=percentage[i]*tickets[i]/100;
    }
    return curr>=k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int test = 0; test<t; test++)
    {
        int n;
        cin>>n;
        tickets.clear();
        tickets.resize(n);
        for(int i = 0; i<n; i++)
        {
            int num;
            cin>>tickets[i];
        }
        sort(tickets.begin(),tickets.end(),greater<long long>());
        cin>>x>>a;
        cin>>y>>b;
        cin>>k;
        int l = 0;
        int r = n;
        int ans=-1;
        while(l<=r)
        {
            int mid = (l+r+1)/2;
            if(works(mid))
            {
                ans=mid;
                r = mid-1;
            }
            else
                l = mid+1;
        }
        cout<<ans<<endl;
    }
}