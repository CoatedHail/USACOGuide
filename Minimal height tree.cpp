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
        vector<int> h(n,INT_MAX);
        for(int i =0 ; i<n; i++)
            cin>>v[i];
        h[0]=0;
        int last = 0;
        for(int i = 1; i<n; i++)
        {
            if(i-1>0&&v[i-1]>v[i])
                last++;
            h[i]=h[last]+1;
        }
        cout<<h[n-1]<<endl;
    }
}