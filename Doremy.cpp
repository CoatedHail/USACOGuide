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
        int n,q;
        cin>>n>>q;
        vector<int> a(n+1),b(n+1);
        for(int i = 1; i<=n; i++)
            cin>>a[i];
        int sum =0;
        int nq = 0;
        for(int i =n; i>=1; i--)
        {
            if(a[i]<=nq)
                b[i]=1;
            else if(nq<q) {
                nq++;
                b[i]=1;
            }
            else
                b[i]=0;
        }
        for(int i = 1; i<=n; i++)
        {
            cout<<b[i];
        }
        cout<<endl;
    }
}
