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

long long corridor,firecracker,robber,police,timecaught,maxcracker;

bool works(vector<long long> explodingt, long long exploded)
{
    int currt = 1;
    for(int i = exploded-1; i>=0; i--)
    {
        if(currt + explodingt[i]>timecaught)
            return false;
        else
            currt++;
    }
    return true;
}
void solve()
{
    cin>>corridor>>firecracker>>robber>>police;
    vector<long long> explodingtime(firecracker);
    for(int i =0; i<firecracker; i++)
    {
        cin>>explodingtime[i];
    }
    sort(explodingtime.begin(),explodingtime.end());
    maxcracker = min(firecracker, abs(police-robber)-1);
    if(robber<police)
    {
        timecaught = police-1;
    }
    else if(police<robber)
    {
        timecaught = corridor-police;
    }
    else return;
    long long left = 0;
    long long right = maxcracker;
    long long maxexploded = 0;
    long long ans = 0;
    while(left<=right)
    {
        long long mid = (left+right+1)/2;
        if(works(explodingtime,mid))
        {
            ans = mid;
            left = mid+1;
        }
        else
            right = mid-1;
    }
    cout<<ans<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int i =0; i<t; i++)
    {
        solve();
    }
}