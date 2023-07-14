
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

struct arrival
{
    int senor;
    int arrive;
    int depart;
};
bool cmp(arrival& a,arrival& b)
{
    return a.arrive<b.arrive;
}
struct cmp2
{
    bool operator() (const arrival& lhs, const arrival& rhs) const
    {return lhs.senor<rhs.senor;}
};



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("convention2.in", "r", stdin);
    freopen("convention2.out", "w", stdout);
    int n;
    cin>>n;
    vector<arrival> track;
    for(int i = 0; i<n; i++)
    {
        arrival a;
        a.senor = i;
        cin>>a.arrive>>a.depart;
        track.push_back(a);
    }
    sort(track.begin(),track.end(),cmp);

    int time,curr,longest;
    time=curr=longest=0;
    set<arrival,cmp2> grazing;
    while(curr<n||!grazing.empty())
    {
        if(curr<n && track[curr].arrive<=time)
        {
            grazing.insert(track[curr]);
            curr++;
        }
        else if(grazing.empty())
        {
            time = track[curr].arrive+track[curr].depart;
            curr++;
        }
        else
        {
            arrival next = *grazing.begin();
            longest = max(longest, time-next.arrive);
            time+=next.depart;
            grazing.erase(grazing.begin());

        }
    }
    cout<<longest;
}