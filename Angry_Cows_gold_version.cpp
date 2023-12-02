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
    freopen("angry.in","r",stdin);
    freopen("angry.out","w",stdout);
    int n;
    cin>>n;
    vector<long long> v(n);
    for(int i =0 ; i<n; i++)
    {
        cin>>v[i];
        v[i]=v[i]*2;
    }
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end())-v.begin());
    vector<long long> DP[2];
    for(int i =0; i<2; i++)
    {
        long long last=0;
        DP[i].resize(n,INT_MAX);
        DP[i][0]=-2;
        for(int j = 1; j<n; j++)
        {
            while(last+1<j&&abs(v[j] - v[last + 1]) > DP[i][last + 1] + 2)
            {
                last++;
            }
            DP[i][j]=min(abs(v[j] - v[last]), DP[i][last + 1] + 2);
        }
        reverse(v.begin(),v.end());
    }
    reverse(DP[1].begin(),DP[1].end());
    long long i = 0;
    long long j = n-1;
    long long result = INT_MAX;
    while(i<j)
    {
        result=min(result,max((v[j]-v[i])/2,2+max(DP[0][i],DP[1][j])));
        if(DP[0][i+1]<DP[1][j-1])
        {
            i++;
        }
        else
            j--;
    }
    cout<<result/2<<"."<<(result%2?5:0)<<endl;
}