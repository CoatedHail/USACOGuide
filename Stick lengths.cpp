
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
    int n;
    cin>>n;
    vector<int> v;
    for(int i = 0; i<n; i++)
    {
        int num;
        cin>>num;
        v.push_back(num);
    }
    sort(v.begin(),v.end());
    long long median = v[n/2];
    long long ans = 0;
    for(int i = 0; i<n; i++)
    {
        ans+=abs(median-v[i]);
    }
    cout<<ans;


}
