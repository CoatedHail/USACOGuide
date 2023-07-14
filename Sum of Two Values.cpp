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
    int n,x;
    cin>>n>>x;
    vector<pair<int,int>> v;
    for(int i = 0; i<n; i++)
    {
        int num;
        cin>>num;
        v.push_back(make_pair(num,i+1));
    }
    sort(v.begin(),v.end());
    int left = 0, right = n-1;
    if(left==right)
    {
        cout<<"IMPOSSIBLE";
        return 0;
    }
    while(v[left].first+v[right].first!=x)
    {
        if(v[left].first+v[right].first<x)
        {
            left++;
        }
        else if(v[left].first+v[right].first>x)
        {
            right--;
        }
        if(left==right)
        {
            cout<<"IMPOSSIBLE";
            return 0;
        }
    }
    cout<<v[left].second<<" "<<v[right].second;
}