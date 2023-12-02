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

bool get(long long a, long long b, long long x)
{
    if(a==x||b==x) return true;
    if(a<b)
        swap(a,b);
    if(b>a-b) b= a-b;
    if(x>max(a,b)||a==0||b==0)return false;
    long long count = max(1LL,(a-max(x,b))/(2*b));
    return get(a-b*count,b,x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        long long a,b,x;
        cin>>a>>b>>x;
        if(get(a,b,x))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}
