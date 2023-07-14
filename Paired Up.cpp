
#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"
#include "set"
#include "stack"
#include "map"
#include "limits.h"
#include "cstdio"
#include "math.h"
#include <iomanip>
#include <numeric>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);
    long long n;
    cin>>n;
    vector<pair<long long,long long>> v;
    for(int i = 0; i<n; i++)
    {
        int a,b;
        cin>>a>>b;
        v.push_back(make_pair(b,a));
    }
    sort(v.begin(),v.end());
    long long left = 0; long long right = n-1;
    long long biggest = -1;
    while(left<=right)
    {
        int x = min(v[left].second,v[right].second);
        if(v[left].first+v[right].first>biggest)
            biggest=v[left].first+v[right].first;
        if(left==right)
            x=x/2;
        v[left].second-=x;
        v[right].second-=x;
        if(v[left].second==0)
            left++;
        if(v[right].second==0)
            right--;
    }
    cout<<biggest;

}
