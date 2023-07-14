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

#define ll long long
ll n, blame[1001];
vector<pair<pair<ll,ll>,ll>> north,east;
bool stop[1001];

bool cmp_east(pair<pair<ll,ll>, ll> a, pair<pair<ll,ll>, ll> b){
    return a.first.second < b.first.second;
}

bool cmp_west(pair<pair<ll,ll>, ll> a, pair<pair<ll,ll>, ll> b){
    return a.first.first < b.first.first;
}

int main(){

    ios_base:: sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i=0, x, y;i<n;i++){
        char dir;
        cin >> dir >> x >> y;
        if(dir=='N') north.push_back({{x,y},i+1});
        else east.push_back({{x,y},i+1});
    }
    sort(east.begin(),east.end(),cmp_east);
    sort(north.begin(), north.end(), cmp_west);
    for(auto i: east){
        for(auto j: north){
            if(!stop[i.second]&&!stop[j.second]&&i.first.second>=j.first.second&&i.first.first<=j.first.first){
                if(i.first.second-j.first.second>j.first.first-i.first.first){
                    stop[j.second]=1;
                    blame[i.second]+=blame[j.second]+1;
                }
                else if(i.first.second-j.first.second<j.first.first-i.first.first){
                    blame[j.second]+=blame[i.second]+1;
                    stop[i.second]=1;
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
        cout << blame[i] << "\n";
}