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

vector<int> fib(50);
void build()
{
    fib[0]=fib[1]=1;
    for(int i = 2; i<50; i++)
        fib[i]=fib[i-2]+fib[i-1];
}

bool solve(int n, int x, int y)
{
    if(n==1)
        return true;
    if(fib[n-1]<y&&y<=fib[n])
        return false;
    if(fib[n]<=y)
        y-=fib[n];
    return solve(n-1,y,x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    build();
    while(t--) {
        int n,x,y;
        cin>>n>>x>>y;
        if(solve(n,x,y))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}
