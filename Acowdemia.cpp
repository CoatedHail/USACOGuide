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

long long N,K,L;
vector<long long> papers;
bool check(long long mid)
{
    long long totarea = 0;
    for(int i = 0; i<mid; i++)
    {
        if(papers[i]<mid) {
            totarea += mid-papers[i];
            if(abs(mid-papers[i])>K)return false;
        }
    }
    return totarea<=L*K;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>K>>L;
    papers.resize(N);
    for(int i = 0; i<N; i++) {
        cin>>papers[i];
    }
    sort(papers.begin(),papers.end(),greater<long long>());
    long long l = 0;
    long long h = N+1;
    while(l<h)
    {
        long long mid = (l+h+1)/2;
        if(check(mid))
            l = mid;
        else
            h = mid-1;
    }
    cout<<l;
}