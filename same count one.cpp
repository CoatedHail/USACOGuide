#include <iostream>
#include <math.h>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <cstdio>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int>> matrix(n,vector<int>(m,0));
        vector<int> sum(n,0);
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<m; j++) {
                cin >> matrix[i][j];
                sum[i]+=matrix[i][j];
            }
        }
        int tot = 0;
        for(int i = 0; i<n; i++)
            tot+=sum[i];
        if(tot%n){
            cout<<-1<<endl;
            continue;
        }
        tot = tot/n;
        vector<tuple<int,int,int>> ans;
        vector<int> vg,vl;
        for(int j = 0; j<m; j++)
        {
            for(int i = 0; i<n; i++)
            {
                if(sum[i]>tot&&matrix[i][j]) vg.push_back(i);
                if(sum[i]<tot && !matrix[i][j]) vl.push_back(i);
            }
            for(int i = 0; i<min(vl.size(),vg.size()); i++)
            {
                sum[vl[i]]++;
                sum[vg[i]]--;
                ans.push_back({vl[i],vg[i],j});
            }
            vl.clear();
            vg.clear();
        }
        cout<<ans.size()<<endl;
        for(auto x: ans)
            cout<<get<0>(x)+1<<" "<<get<1>(x)+1<<" "<<get<2>(x)+1<<endl;
    }
}

