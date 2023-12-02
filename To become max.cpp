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


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        long long n,k;
        cin>>n>>k;
        vector<long long> v(n);
        for(int i =0; i<n; i++)
            cin>>v[i];
        long long lb = 0;
        long long ub = *max_element(v.begin(),v.end())+k;
        long long ans = 0;
        while(lb<=ub)
        {
            long long mid = (lb+ub)/2;
            bool good = false;
            for(int i = 0; i<n; i++)
            {
                vector<long long> minneed(n);
                minneed[i]=mid;
                long long used = 0;
                for(int j = i; j<n; j++)
                {
                    if(minneed[j]<=v[j])
                        break;
                    if(j+1>=n)
                    {
                        used = k+1;
                        break;
                    }
                    used+=minneed[j]-v[j];
                    minneed[j+1]=max(0LL, minneed[j] - 1);
                }
                if(used<=k)
                    good = true;
            }
            if(good){
                ans = mid;
                lb = mid+1;
            }
            else
            {
                ub = mid-1;
            }
        }
        cout<<ans<<endl;
    }
}
