
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

struct measure
{
    int day;
    int cow;
    int change;
};
bool cmp(measure & x,measure& y) {
    return x.day<y.day;
}
bool cmp2(measure& x, measure& y)
{
    return x.cow<y.cow;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);
    int n,g;
    cin>>n>>g;
    vector<measure> track;
    map<int, int> cows;
    for(int i = 0; i<n; i++)
    {
        measure m;
        cin>>m.day>>m.cow>>m.change;
        cows[m.cow]=g;
        track.push_back(m);
    }

    sort(track.begin(),track.end(),cmp);
    int biggest=g;
    int ans = 0;
    map<int, int> milk_prod{{g, n}};
    for(measure m : track)
    {
        int milkam = cows[m.cow];
        bool wtop = milkam == milk_prod.rbegin()->first;
        int precount = milk_prod[milkam];
        milk_prod[milkam]--;
        if(milk_prod[milkam]==0) milk_prod.erase(milkam);
        milkam+=m.change;
        milk_prod[milkam]++;
        cows[m.cow]=milkam;
        bool itop = milkam == milk_prod.rbegin()->first;
        int curcount = milk_prod[milkam];
        if(wtop)
        {
            if(itop&&precount==curcount) continue;
            ans++;
        }
        else if(itop)
        {
            ans++;
        }
    }
    cout<<ans;
}
