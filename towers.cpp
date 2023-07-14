
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

bool cmp(int a,int b)
{
    return a>b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    multiset<int> v;
    for(int i = 0; i<n; i++)
    {
        int num;
        cin>>num;
        auto it = v.upper_bound(num);
        if(it!=v.end())
        {
            v.erase(it);
        }
        v.insert(num);
    }
    cout<<v.size();
}
