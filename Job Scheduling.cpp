#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"
#include "set"
#include "unordered_set"
#include "stack"
#include "map"
#include "limits.h"
#include "cstdio"
#include "math.h"
#include <iomanip>
#include <numeric>
using namespace std;

int N,D,M;

pair<bool,vector<vector<int>>> works(const vector<pair<int,int>> &jobs, int machines)
{
    vector<vector<int>> schedule(N);
    int reqnum = 0;
    for(int day = 1; day<=N; day++)
    {
        for(int j = 0; j<machines; j++)
        {
            if(jobs[reqnum].first>day)break;
            if(jobs[reqnum].first+D>=day)
                schedule[day-1].push_back(jobs[reqnum++].second);
            else
                return make_pair(false,schedule);
            if(reqnum==M)
                return make_pair(true,schedule);
        }
    }
    return make_pair(false,schedule);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>D>>M;
    vector<pair<int,int>> jobs(M);
    for(int i = 0; i<M; i++)
    {
        int day;
        cin>>day;
        jobs[i]=make_pair(day,i+1);
    }
    sort(jobs.begin(),jobs.end());
    vector<vector<int>> result;
    int l = 1; int r= M;
    while(l<r)
    {
        int mid = (l+r)/2;
        pair<bool,vector<vector<int>>> res = works(jobs,mid);
        if(res.first == true)
        {
            r = mid;
            result = res.second;
        }
        else
            l = mid+1;
    }
    cout<<l<<endl;
    for(int i = 0; i<N; i++)
    {
        for(auto x: result[i])
        {
            cout<<x<<" ";
        }
        cout<<0<<endl;
    }
}