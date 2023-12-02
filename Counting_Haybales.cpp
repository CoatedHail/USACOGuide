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
    freopen("haybales.in","r",stdin);
    freopen("haybales.out","w",stdout);
    int n,q;
    cin>>n>>q;
    vector<int> haybales;
    for(int i =0; i<n; i++)
    {
        int num;
        cin>>num;
        haybales.push_back(num);
    }
    sort(haybales.begin(),haybales.end());
    for(int i = 0; i<q; i++)
    {
        int start,end;
        cin>>start>>end;
        cout<<upper_bound(haybales.begin(),haybales.end(), end)-lower_bound(haybales.begin(),haybales.end(),start)<<endl;
    }
}