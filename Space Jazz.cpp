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
#include <numeric>
using namespace std;

vector<int> arr;
vector<vector<int>> cache;
int mininotes(int l,int r)
{
    int size = r-l+1;
    if(size<=0)
        return 0;
    if(size==1)
        return 1;
    if(cache[l][r]!=-1)
        return cache[l][r];
    if (arr[l]==arr[r])
        return mininotes(l+1,r-1);
    int ans = 1000;
    for(int i = 1; i<size; i++)
    {
        ans = min(ans, mininotes(l,r-i)+mininotes(r-i+1,r));

    }
    cache[l][r]=ans;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    stack<int> v;
    string s;
    cin>>s;
    for(int i =0 ; i<s.size(); i++)
    {
        int convert = s[i]-'a'+1;
        if(v.empty())
            v.push(convert);
        else
        {
            if(convert == v.top())
                v.pop();
            else
                v.push(convert);
        }
    }

    while(!v.empty())
    {
        int num = v.top();
        arr.push_back(num);
        v.pop();
    }
    cache.resize(arr.size(),vector<int>(arr.size(),-1));
    cout<<mininotes(0,arr.size()-1);
}
