#include <iostream>
#include <math.h>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cstdio>

using namespace std;

const int mod = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,x;
        cin>>n>>m>>x;
        set<pair<int,int>>s;
        cout<<"YES\n";
        vector<int> H(n);
        for (int i=1;i<=m;i++)
            s.insert({0,i});
        for (int i=0;i<n;i++){
            cin>>H[i];
            pair<int,int>p=*s.begin();
            s.erase(p);
            cout<<p.second<<' ';
            s.insert({p.first+H[i],p.second});
        }
        cout<<endl;
    }
}
