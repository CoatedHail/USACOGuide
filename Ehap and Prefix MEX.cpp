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
    int n;
    cin>>n;
    vector<int> v(n+1,0);
    vector<bool> ex(n+1);
    for(int i =1 ; i<=n; i++)
        cin>>v[i];
    vector<int> b(n+1,-1);
    for(int i = 1; i<=n; i++)
    {
        if(v[i]!=v[i-1]) {
            b[i]=v[i-1];
            ex[b[i]]=1;
        }
    }
    ex[v[n]]=1;
    int m = 0;
    for(int i = 1; i<=n; i++)
    {
        while(ex[m])
            m++;
        if(b[i]==-1)
        {
            b[i]=m;
            ex[m]=1;
        }
        cout<<b[i]<<" ";
    }
}
