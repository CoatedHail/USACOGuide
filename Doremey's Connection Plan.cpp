#include <iostream>
#include <math.h>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <set>
#include <unordered_map>
#include <iomanip>
#include <cstdio>

using namespace std;

const int mod = 1e9+7;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long t;
    cin>>t;
    while(t--)
    {
        int n,c;
        cin>>n>>c;
        bool works = true;
        vector<long long> a(n+1);
        vector<int> p(n+1);
        for(int i =1; i<=n; i++)
            cin>>a[i];
        for(int i =1; i<=n; i++)
        {
            p[i]=i;
        }
        sort (p .begin()+1, p.end(), [&] (const int &u, const int &v) {
            return 1ll * u * c - a[u] < 1ll * v * c - a[v];
        });
        long long now = a[1];
        for(int i =1,u; i<=n; i++) {
            u = p[i];
            if (u == 1)
                continue;
            if (1ll * u * c > (now + a[u])) {
                works = false;
                break;
            }
            now+=a[u];
        }
        if(works)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}
