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
    long long b,s,c;
    b = s = c = 0;
    string string1;
    cin>>string1;
    for(char x: string1)
    {
        if(x == 'B')
            b++;
        else if(x=='S')
            s++;
        else
            c++;
    }
    long long nb,ns,nc;
    cin>>nb>>ns>>nc;
    long long pb,ps,pc;
    cin>>pb>>ps>>pc;
    long long rubles;
    cin>>rubles;
    long long l = 0;
    long long r= 1e15;
    long long ans =0;
    while(l<=r)
    {
        long long mid = (l+r)/2;
        long long bprice,sprice,cprice;
        bprice = (b*mid-nb);
        sprice = (s*mid-ns);
        cprice = (c*mid-nc);
        if(bprice<0)
            bprice = 0;
        if(sprice<0)
            sprice = 0;
        if(cprice<0)
            cprice = 0;
        long long needed = bprice*pb+sprice*ps+cprice*pc;
        if(needed>rubles)
        {
            r = mid-1;
        }
        else
        {

            l = mid+1;
            ans = mid;
        }
    }
    cout<<ans;
}
