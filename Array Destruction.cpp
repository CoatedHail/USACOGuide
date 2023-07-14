
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

int size;
vector<int> arr;
vector<pair<int,int>> dele;
bool works(int initial) {
    dele.clear();
    multiset<int> remaining;
    for (int i = 0; i < size; i++) { remaining.insert(arr[i]); }
    while (remaining.size())
    {
        int curr = *remaining.rbegin();
        remaining.erase(remaining.find(curr));
        if(remaining.find(initial-curr)==remaining.end())
        {
            return false;
        }
        remaining.erase(remaining.find(initial-curr));
        dele.push_back(make_pair(curr,initial-curr));
        initial = curr;
    }
    return true;
}

void solve()
{
    arr.clear();
    cin>>size;
    size*=2;
    for(int i = 0; i<size; i++)
    {
        int num;
        cin>>num;
        arr.push_back(num);
    }
    sort(arr.begin(),arr.end());
    for(int i = 0; i<size; i++)
    {
        int inital = arr[i]+arr[size-1];
        if(works(inital))
        {
            cout<<"YES"<<endl<<inital<<endl;
            for(pair<int,int> p : dele)
            {
                cout<<p.first<<" "<<p.second<<endl;
            }
            return;
        }
    }
    cout<<"NO"<<endl;
    return;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int i = 0; i<t; i++)
    {
        solve();
    }
}
