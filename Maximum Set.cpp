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

const long long MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        long long a,b;
        cin>>a>>b;
        int maxy = 1;
        while((a<<maxy)<=b)
            maxy++;
        int ans = (b/(1<<(maxy-1))-a+1);
        if(maxy>1)
            ans+=(maxy-1)*max((long long)0, (b / (1 << (maxy - 2)) / 3 - a + 1));
        cout<<maxy<<" "<<ans<<endl;
    }
}

