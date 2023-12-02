
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


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,t,k;
    cin>>n>>t>>k;
    int l =1; int r=n;
    while(true)
    {
        if(l==r){
            cout<<"! "<<l<<endl;
            return 0;
        }
        int m = (l+r)/2;
        cout<<"? "<<l<<" "<<m<<endl;
        int sum;
        cin>>sum;
        if((m-l+1)-sum>=k)
            r=m;
        else
        {
            l=m+1;
            k=k-(m-l+1)+sum;
        }
    }
}