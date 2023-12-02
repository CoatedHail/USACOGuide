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

vector<long long> presum,prexor;
long long cost(int l, int r)
{
    return (presum[r]-presum[l-1])-(prexor[r]^prexor[l-1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int test = 0; test<t; test++)
    {
        int n,q;
        cin>>n>>q;
        presum.clear();
        prexor.clear();
        presum.resize(n+1,0);
        prexor.resize(n+1,0);
        for(int i = 0; i<n; i++)
        {
            int x;
            cin>>x;
            presum[i+1]=presum[i]+x;
            prexor[i+1]=x^prexor[i];
        }
        int L,R;
        cin>>L>>R;
        long long most = cost(1,n);
        int lo = 1;
        int high = n;
        while(lo<=high)
        {
            int mid = (lo+high+1)/2;
            bool possible = false;
            for(int i = 1; i+mid-1<=n; i++)
            {
                if(cost(i,i+mid-1)==most)
                {
                    possible = true;
                    break;
                }
            }
            if(possible)
            {
                high = mid-1;
            }
            else
                lo = mid+1;
        }
        for(int i = 1; i+lo-1<=n; i++)
        {
            if(cost(i,i+lo-1)==most) {
                cout << i << " " << i + lo - 1 << endl;
                break;
            }
        }
    }
}
