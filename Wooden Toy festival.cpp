#include <iostream>
#include <math.h>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <cstdio>

using namespace std;

const int mod = 1e9+7;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i = 0; i<n; i++)
            cin>>v[i];
        sort(v.begin(),v.end());
        int l = 0;
        int r = v[n-1];
        int ans=0;
        while(l<=r)
        {
            int mid = (l+r)/2;
            int curr=0;
            while(curr<v.size()-1&&v[curr+1]-v[0]<=2*mid)
                curr++;
            int j = n-1;
            while(j-1>=0&&v.back()-v[j-1]<=2*mid)
                j--;
            curr++;
            j--;
            if(curr>j||v[j]-v[curr]<=2*mid)
            {
                ans = mid;
                r = mid-1;
            }
            else
                l= mid+1;

        }
        cout<<ans<<endl;
    }
}
