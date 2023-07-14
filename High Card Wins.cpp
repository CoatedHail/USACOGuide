
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("highcard.in", "r", stdin);
    freopen("highcard.out", "w", stdout);
    int n;
    cin>>n;
    vector<long long> elsie;
    int csize = 2*n+1;
    vector<bool> cards(csize,false);
    set<long long> bessie;
    for(int i = 0; i<n; i++)
    {
        long long num;
        cin>>num;
        elsie.push_back(num);
        cards[num]=true;
    }
    for(int i = 1; i<=2*n; i++)
    {
        if(cards[i]==false)
            bessie.insert(i);
    }
    long long win =0;
    for(int i = 0; i<n; i++)
    {
        auto it = bessie.upper_bound(elsie[i]);
        if(it!=bessie.end())
        {
            bessie.erase(it);
            win++;
        }

    }
    cout<<win;
}