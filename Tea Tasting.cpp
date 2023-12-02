#include <iostream>
#include <math.h>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cstdio>

using namespace std;

const int mod = 1e9+7;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        vector<long long> add(n+1,0),a(n+1,0),b(n+1,0),maxes(n+1,0);
        for(int i = 1; i<=n; i++)
            cin>>a[i];
        for(int i = 1; i<=n; i++) {
            cin >> b[i];
        }
        vector<long long> real = b;
        for(int i = 1; i<=n; i++)
        {
            b[i]+=b[i-1];
        }
        for(int i = 1; i<=n; i++)
        {
            long long l= 0;
            long long r = n;
            long long ind= 0;
            while(l<=r)
            {
                long long mid = (l+r+1)/2;
                if(b[mid]-b[i-1]>a[i])
                {
                    ind = mid;
                    r = mid-1;
                }
                else
                    l = mid+1;
            }
            if(ind==0)
            {
                maxes[i]++;
                continue;
            }
            long long remainder = a[i]-b[ind-1]+b[i-1];
            add[ind]+=remainder;
            maxes[i]++;
            maxes[ind]--;
        }
        for(int i = 1; i<=n; i++)
            maxes[i]+=maxes[i-1];
        for(int i = 1; i<=n; i++)
        {
            cout<<maxes[i]*real[i]+add[i]<<" ";
        }
        cout<<endl;
    }
}
