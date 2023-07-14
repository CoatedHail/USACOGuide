
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
    vector<pair<int,int>> v;
    for(int i = 0; i<n; i++)
    {
        int start,end;
        cin>>start>>end;
        v.push_back(make_pair(end,start));
    }
    sort(v.begin(),v.end());
    int count = 1;
    int curr = 0;
    for(int i = 1; i<n; i++)
    {
        if(v[i].second>=v[curr].first) {
            count++;
            curr=i;
        }
    }
    cout<<count;
}
