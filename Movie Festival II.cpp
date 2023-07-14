
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
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>> v;
    for(int i = 0; i<n; i++)
    {
        int start,end;
        cin>>start>>end;
        v.push_back(make_pair(end,start));
    }
    sort(v.begin(),v.end());
    int max = 0;
    multiset<int> end;
    for(int i = 0; i<k; i++)
    {
        end.insert(0);
    }
    for(int i = 0; i<n; i++)
    {
        auto it = end.upper_bound(v[i].second);
        if(it == end.begin())
            continue;
        end.erase(--it);
        end.insert(v[i].first);
        max++;
    }
    cout<<max;
}
