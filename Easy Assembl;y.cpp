#include <iostream>
#include <math.h>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <cstdio>

using namespace std;

const int mod = 1e9+7;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<vector<int>> towers;
    set<int> st;
    map<int,int> location;
    long long split = 0, m = 0;
    for(int i = 0; i<n; i++)
    {
        int x;
        cin>>x;
        vector<int> v(x);
        for(int j = 0; j<x; j++) {
            cin >> v[j];
            st.insert(v[j]);
        }
        towers.push_back(v);
    }
    int a = 1;
    for(auto x: st)
    {
        location[x] = a;
        a++;
    }
    long long prev = -1;
    for(int i = 0; i<n; i++)
    {
        for(int j =0 ; j<towers[i].size()-1; j++)
        {
            auto it1 = location[towers[i][j]];
            auto it2 = location[towers[i][j+1]];
            if(it1+1!=it2)
                split++;
        }
    }
    cout<<split<<" "<<n+split-1;
}
