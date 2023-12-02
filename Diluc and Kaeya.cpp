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


int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int test =0 ; test<t; test++)
    {
        int n,  dnum = 0, knum = 0;
        string s;
        cin>>n>>s;
        map<pair<int,int>,int> track;
        for(int i = 0; i<n; i++)
        {
            if(s[i]=='D')dnum++;
            else
                knum++;
            int d1 = dnum/gcd(dnum,knum);
            int k1 = knum/gcd(dnum,knum);
            track[make_pair(d1,k1)]++;
            cout<<track[make_pair(d1,k1)]<<" ";
        }
        cout<<endl;
    }
}