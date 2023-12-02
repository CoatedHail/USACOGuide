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

int N;
vector<int> x;
set<multiset<int>> sols;

void checksol(int sum, int b, int c)
{
    int a = sum-b-c;
    set<int> s{0,a,b,c,a+b,b+c,c+a,a+b+c};
    for(int t:x)
    {
        if(!s.count(t)) return;
    }
    sols.insert({a,b,c});
}
void test(int sum)
{
    set<int> candidates;
    for(int t: x)
    {
        if(t>sum) return;
        if(t==0 || t==sum) continue;
        candidates.insert(min(t,sum-t));
    }
    int a = *begin(candidates);
    int b= *next(begin(candidates));
    checksol(sum,a,b);
    checksol(sum,a,sum-b);
}

int solve()
{
    cin>>N;
    x.resize(N);
    for(int i = 0; i<N; i++)
        cin>>x[i];
    x.push_back(0);
    sols.clear();
    for(int i = 0; i<x.size(); i++)
    {
        for(int j = i+1; j<x.size(); j++)
            test(x[i]+x[j]);
    }
    return sols.size();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
        cout<<solve()<<endl;
}