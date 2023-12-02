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
    long long t;
    cin>>t;
    vector<long long> ans(2000001);
    vector<vector<long long>> a(1501,vector<long long>(1501,0));
    long long curr = 1;
    for(int i = 1; i<1501; i++)
    {
        for(int j = i-1; j>=1; j--)
        {
            a[j][i-j]=a[j-1][i-j]+a[j][i-j-1]-a[j-1][i-j-1]+curr*curr;
            ans[curr]=a[j][i-j];
            curr++;
        }
    }

    while(t--) {
        long long n;
        cin>>n;

        cout<<ans[n]<<endl;
    }
}
