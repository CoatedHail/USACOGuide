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
    int n,k;
    cin>>n>>k;
    vector<int> seq(n);
    for(int i = 0; i<n; i++)
    {
        cin>>seq[i];
    }
    sort(seq.begin(),seq.end());
    vector<int> leftpre;
    vector<int> rightpre;
    leftpre = seq;
    rightpre=seq;
    for(int i = 1; i<n; i++)
    {
        leftpre[i]+=leftpre[i-1];
    }
    for(int i = n-2; i>=0; i--)
    {
        rightpre[i]+=rightpre[i+1];
    }
    int l = 0;
    int r = seq[n-1]-seq[0];
    while(l<r)
    {
        int medium = (l+r)/2;

    }
}