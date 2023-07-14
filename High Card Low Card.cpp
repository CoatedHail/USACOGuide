
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

bool cmp(long long a,long long b)
{
    return a>b;
}
bool cmp2(long long a,long long b)
{
    return a<b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);
    int n;
    cin>>n;
    vector<long long> elsie1,elsie2;
    int csize = 2*n+1;
    vector<bool> cards(csize,false);
    vector<long long> bessie1,bessie2;
    for(int i = 0; i<n; i++)
    {
        long long num;
        cin>>num;
        if(i<n/2)
            elsie1.push_back(num);
        else
            elsie2.push_back(num);
        cards[num]=true;
    }
    vector<int> v;
    for(int i = 1; i<=2*n; i++)
    {
        if(cards[i]==false)
        {
            v.push_back(i);
        }
    }
    sort(v.begin(),v.end(),cmp);
    for(int i = 0; i<n/2; i++)
    {
        bessie1.push_back(v[i]);
    }
    for(int i = n/2; i<n; i++)
        bessie2.push_back(v[i]);
    long long win =0;
    auto apos = 0;
    sort(elsie1.begin(),elsie1.end());
    sort(elsie2.begin(),elsie2.end());
    sort(bessie1.begin(),bessie1.end());
    sort(bessie2.begin(),bessie2.end());
    for(int i = 0; i<n/2; i++)
    {
        while(!cmp(bessie1[apos],elsie1[i])) {
            apos++;
            if(apos>=n/2)
                break;
        }
        if(apos>=n/2)
            break;
        apos++;
        win++;
    }
    auto bpos = (n-1)/2;
    for(int i = (n/2)-1; i>=0; i--)
    {
        while(!cmp2(bessie2[bpos],elsie2[i])) {
            bpos--;
            if(bpos<=-1)
                break;
        }
        if(bpos<=-1)
            break;
        bpos--;
        win++;

    }
    cout<<win;
}