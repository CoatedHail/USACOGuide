#include <iostream>
#include <math.h>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <cstdio>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t;
    cin>>t;
    while(t--)
    {
        int n,s;
        cin>>n>>s;
        vector<vector<long long>> f(n+1,vector<long long>(2));
        vector<long long> x(n+1),y(n+1);
        for(int i = 1; i<=n; i++) {
            long long num;
            cin >> num;
            if (i == 1 || i == n)
                x[i] = y[i] = num;
            else if (num <= s) {
                x[i] = 0;
                y[i] = num;
            } else
            {
                x[i]=s;
                y[i]=num-s;
            }
        }
        f[1][0]=f[1][1]=0;
        for(int i = 2; i<=n; i++)
        {
            f[i][0]=min(f[i-1][0]+y[i-1]*x[i],f[i-1][1]+x[i-1]*x[i]);
            f[i][1]=min(f[i-1][0]+y[i-1]*y[i],f[i-1][1]+x[i-1]*y[i]);
        }
        cout<<f[n][0]<<endl;
    }
}

