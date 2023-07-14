
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
    vector<pair<long long,long long>> v;
    for(int i = 0; i<n; i++)
    {
        int dur,dead;
        cin>>dur>>dead;
        v.push_back(make_pair(dur, dead));
    }
    sort(v.begin(),v.end());
    long long points = 0;
    long long time = 0;
    for(int i = 0; i<n; i++)
    {
        time+=v[i].first;
        points+=(v[i].second-time);
    }
    cout<<points;
}
