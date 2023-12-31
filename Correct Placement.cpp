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
using ll = long long;
using pl = pair<ll, ll>;

struct Friend {
    ll h, w, i;
};

bool cmp(Friend a, Friend b){
    if(a.h == b.h){
        return a.w > b.w;
    } else {
        return a.h < b.h;
    }
}

void solve(int tc){
    int n; cin >> n;
    vector<Friend> photo(n+1);
    for(int i=1; i<=n; i++){
        cin >> photo[i].h >> photo[i].w;
        if(photo[i].h < photo[i].w){
            swap(photo[i].h, photo[i].w);
        }
        photo[i].i = i;
    }
    sort(photo.begin()+1, photo.end(), cmp);
    vector<int> overlap(n+1, -1);
    int x = photo[1].i, y = photo[1].w;
    for(int i=2; i<=n; i++){
        if(photo[i].w > y){
            overlap[photo[i].i] = x;
        } else {
            x = photo[i].i;
            y = photo[i].w;
        }
    }
    for(int i=1; i<=n; i++){
        cout << overlap[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    for(int i=1; i<=t; i++){
        solve(i);
    }
}
