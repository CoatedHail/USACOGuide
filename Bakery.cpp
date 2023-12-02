#include <iostream>
#include <math.h>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cstdio>

using namespace std;

long long n,cookie,muffin;
vector<long long> numc(n),numm(n),times(n);
bool check(long long w) {
    for (long long x = 0; x <= cookie; x++) {
        for(long long y = 0; y<=muffin; y++)
        {
            if(x+y==cookie+muffin-w)
            {
                bool works = true;
                for(long long i = 0; i<n; i++) {
                    if (numc[i] * x + numm[i] * y > times[i])
                    {
                        works = false;
                        break;
                    }
                }
                if(works == true)
                    return true;
            }
        }
    }

    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long t;
    cin>>t;
    for(int z = 0; z<t; z++)
    {

        cin>>n>>cookie>>muffin;
        numc.resize(n);
        numm.resize(n);
        times.resize(n);
        for(int i = 0; i<n; i++)
        {
            cin>>numc[i]>>numm[i]>>times[i];
        }
        long long l = 0;
        long long r = cookie+muffin;
        while(l<r)
        {
            long long medium = (l+r)/2;
            if(check(medium))
            {
                r = medium;
            }
            else
                l = medium+1;
        }
        cout<<r<<endl;
    }
}