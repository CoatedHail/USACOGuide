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
#include <numeric>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<long long> prod(n);
    for(int i = 0; i<n; i++)
        cin>>prod[i];
    vector<long long> a(prod);
    sort(a.begin(),a.end());
    vector<long long> suffix(n+1);
    long long ans =0;
    for(int i = n-1; i>=0; i--)
    {
        if(i<n-1) suffix[i]=suffix[i+1];
        suffix[i]+=a[i];
        ans+=suffix[i];
    }
    int q;
    cin>>q;
    while(q--)
    {
        int index;
        long long newv;
        cin>>index>>newv;
        int newi = lower_bound(a.begin(),a.end(),newv)-a.begin();
        int oldi = lower_bound(a.begin(),a.end(),prod[index-1])-a.begin();
        long long curra = ans;
        if(newi<=oldi)
        {
            curra+=suffix[newi]-suffix[oldi];
            curra-=(oldi+1)*prod[index-1];
            curra+=(newi+1)*newv;
        }
        else
        {
            curra-=suffix[oldi+1]-suffix[newi];
            curra-=(oldi+1)*prod[index-1];
            curra+=(newi)*newv;
        }
        cout<<curra<<endl;
    }
}
