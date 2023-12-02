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

pair<long long, long long> operator+(pair<long long, long long> a, pair<long long, long long> b) { return {a.first + b.first, a.second + b.second}; }
pair<long long, long long> operator-(pair<long long, long long> a, pair<long long, long long> b) { return {a.first - b.first, a.second - b.second}; }

vector<int> solutions;
vector<pair<pair<long long, long long>, int>> solve(const vector<pair<long long, long long>> &dirs) {
    vector<pair<pair<long long, long long>, int>> v{{}};
    for (const pair<long long, long long> &d : dirs) {
        v.resize(2 * v.size());
        for (int i = 0; i < v.size() / 2; i++) {
            v[i + v.size() / 2] = {v[i].first + d, v[i].second + 1};
        }
    }
    sort(v.begin(), v.end());
    return v;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    pair<long long, long long> goal;
    vector<pair<long long, long long>> instructions;
    cin>>goal.first>>goal.second;
    solutions.resize(n+1,0);
    for(int i = 0; i<n; i++)
    {
        int a,b;
        cin>>a>>b;
        instructions.push_back({a,b});
    }
    vector<pair<pair<long long,long long>,int>> a = solve(vector<pair<long long,long long>>(instructions.begin(),instructions.begin()+n/2));
    vector<pair<pair<long long,long long>,int>> b = solve(vector<pair<long long,long long>>(instructions.begin()+n/2,instructions.end()));
    reverse(b.begin(),b.end());
    vector<long long> ans(n+1);
    vector<int> withn;
    pair<long long, long long> restv{1e18,1e18};
    int ib = 0;
    for(const auto &[offset,num]:a)
    {
        const pair<long long, long long> rest = goal-offset;
        if(rest!=restv)
        {
            restv = rest;
            withn = vector<int>(n-n/2+1);
            for(; ib<b.size()&&b.at(ib).first>rest; ib++);
            for(; ib<b.size()&&b.at(ib).first==rest; ib++)
            {
                withn.at(b.at(ib).second)++;
            }
        }
        for(int i =0; i<withn.size(); i++)
            ans[i+num]+=withn[i];
    }
    for(int i = 1; i<=n; i++)
        cout<<ans[i]<<"\n";
}