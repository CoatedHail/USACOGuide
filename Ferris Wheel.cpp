
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x;
    cin>>n>>x;
    vector<int> v;
    for(int i = 0; i<n; i++)
    {
        int num;
        cin>>num;
        v.push_back(num);
    }
    sort(v.begin(),v.end());
    int l,r;
    l = 0; r= n-1;
    int ans = 0;
    while(l<r)
    {
        if(v[l]+v[r]<=x)
        {
            l++;
            r--;
            ans++;
            n-=2;
        }
        else
        {
            r--;
        }
    }
    cout<<n+ans;
}
