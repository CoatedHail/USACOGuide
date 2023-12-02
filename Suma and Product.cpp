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
        int n;
        cin>>n;
        map<long long,long long> count;
        vector<long long> v(n);
        for(int i =0; i<n; i++)
        {
            cin>>v[i];
            count[v[i]]++;
        }
        long long q;
        cin>>q;
        for(long long i = 0; i<q; i++)
        {
            long long b,c;
            cin>>b>>c;
            long long d = b*b-4*c;
            if(d<0) {
                cout << 0<<" ";
                continue;
            }
            long long x1, x2;
            x1 = (b-sqrt(d))/2;
            x2 = (b+sqrt(d))/2;
            if(x1+x2!=b||x1*x2!=c) {
                cout << 0<<" ";
                continue;
            }
            if(x1==x2)
            {
                cout<<count[x1]*(count[x1]-1)/2;
            }
            else
                cout<<count[x1]*count[x2];
            cout<<" ";
        }
        cout<<endl;
    }
}


