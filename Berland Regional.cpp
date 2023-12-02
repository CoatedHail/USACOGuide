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
        int n;
        cin>>n;
        vector<int> u(n+1);
        vector<int> skills(n+1);
        for(int i =1 ; i<=n; i++)
        {
            cin>>u[i];
        }
        for(int i = 1; i<=n; i++)
            cin>>skills[i];
        vector<vector<int>> bst(n+1);
        for(int i = 1; i<=n; i++)
        {
            bst[u[i]].push_back(skills[i]);
        }
        for(int i = 1; i<=n; i++)
        {
            sort(bst[i].begin(),bst[i].end(),greater<int>());
        }
        vector<vector<long long>> pr(n+1,vector<long long>(1,0));
        for(int i = 1; i<=n; i++)
        {
            for(int x: bst[i])
                pr[i].push_back(pr[i].back()+x);
        }
        vector<long long> ans(n);
        for(int i =1 ; i<=n; i++)
        {
            for(int k = 1; k<=bst[i].size(); k++)
            {
                ans[k-1]+=pr[i][bst[i].size()/k*k];
            }
        }
        for(int i = 0; i<n; i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
}
