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

const int STREET = 1e6;
vector<int> locations(1000);
int n,k;
bool works(int length)
{
    for(int i = 0; i<n; i++)
    {
        int needed = 0;
        int start = locations[i];
        for(int j = 1; j<n; j++)
        {
            int end = locations[(i+j)%n];
            int distance = (end-start+STREET)%STREET;
            if(distance>2*length)
            {
                start = end;
                needed++;
            }
        }
        needed++;
        if(needed<=k)
            return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i = 0; i<n; i++)
    {
        cin>>locations[i];
    }
    cin>>k;
    sort(locations.begin(),locations.begin()+n);
    int l = 0;
    int r =1e6;
    int ans = 0;
    while(l<=r)
    {
        int mid = (l+r)/2;
        if(works(mid))
        {
            ans = mid;
            r = mid-1;
        }
        else
            l = mid+1;
    }
    cout<<ans;
}