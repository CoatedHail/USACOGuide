
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

vector<int> ans(200001);
vector<pair<pair<int,int>,int>> v;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    v.resize(n);

    for(int i = 0; i<n; i++)
    {
        cin>>v[i].first.first>>v[i].first.second;
        v[i].second = i;
    }
    sort(v.begin(),v.end());
    int rooms=0; int last = 0;
    priority_queue<pair<int,int>> pq;
    for(int i = 0; i<n; i++)
    {
        if(pq.empty())
        {
            last++;
            pq.push(make_pair(-v[i].first.second,last));
            ans[v[i].second] = last;
        }
        else {
            pair<int, int> mini = pq.top();
            if (-mini.first < v[i].first.first)
            {
                pq.pop();
                pq.push(make_pair(-v[i].first.second, mini.second));
                ans[v[i].second] = mini.second;
            }
            else {
                last++;
                pq.push(make_pair(-v[i].first.second, last));
                ans[v[i].second] = last;
            }
        }
        rooms = max(rooms, int(pq.size()));
    }
    cout<<rooms<<endl;
    for (int i = 0; i < n; i++) {
        cout <<ans[i] << " ";
    }
}
