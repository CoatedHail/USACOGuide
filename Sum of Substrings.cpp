#include <iostream>
#include <math.h>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <queue>
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
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        int ones = 0;
        int p1_first = n, p1_last = -1;
        for(int i = 0; i<n; i++)
        {
            if(s[i]!='1')
                continue;
            ones+=1;
            if(p1_first == n)
                p1_first = i;
            p1_last = i;
        }
        int add = 0;
        if(ones>0 && (n-1-p1_last)<=k)
        {
            k-=(n-1-p1_last);
            add+=1;
            ones-=1;
        }
        if(ones>0&&p1_first<=k)
        {
            k-=(p1_first);
            add+=10;
            ones-=1;
        }
        cout<<11*ones+add<<endl;
    }
}
