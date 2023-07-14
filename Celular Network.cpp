
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
    int n,m;
    cin>>n>>m;
    vector<int> cities, towers;
    for(int i = 0; i<n; i++)
    {
        int num;
        cin>>num;
        cities.push_back(num);
    }
    for(int i = 0; i<m; i++)
    {
        int num;
        cin>>num;
        towers.push_back(num);
    }
    int l,r,ans;
    l = r = ans = 0;
    for(int i = 0; i<n; i++)
    {
        while(r+1<m&&towers[r]<cities[i])
        {
            r++;
        }
        if(r!=0)
            l=r-1;
        ans = max(ans, min(abs(towers[r]-cities[i]),abs(towers[l]-cities[i])));
    }
    cout<<ans;
}
