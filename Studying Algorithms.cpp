
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
    int n,x;
    cin>>n>>x;
    vector<int> v;
    for(int i = 0; i<n; i++)
    {
        int num;
        cin>>num;
        v.push_back(num);
    }
    sort(v.begin(),v.end());
    int count = 0;
    for(int i = 0; i<n; i++)
    {
        if(v[i]<=x)
        {
            x-=v[i];
            count++;
        }
        else
        {
            cout<<count;
            return 0;
        }
    }
    cout<<count;
}
