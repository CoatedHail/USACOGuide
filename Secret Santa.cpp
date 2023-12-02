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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        long long n, total=0;
        cin>>n;
        vector<long long> wish(n),ans(n),pos(n+1);
        vector<bool> used(n+1),vis(n+1);
        set<long long> s;
        for(int i =0; i<n; i++) {
            cin >> wish[i];
            s.insert(i+1);
        }
        for(int i =0 ; i<n; i++)
        {
            if(!used[wish[i]]) {
                used[wish[i]] = vis[i] = 1;
                total++;
                s.erase(wish[i]);
                pos[wish[i]]=i;
            }
        }
        for(int i =0; i<n; i++)
        {
            if(!vis[i])
            {
                auto it = s.begin();
                long long val = 0;
                if((*it)!=(i+1)) {
                    wish[i] = (*it);
                    used[wish[i]]=1;
                    pos[wish[i]]=i;
                    val=wish[i];
                }
                else
                {
                    long long id = pos[wish[i]];
                    wish[i]=*it;
                    swap(wish[i],wish[id]);
                    pos[wish[i]]=i;
                    pos[wish[id]]=id;
                }
                s.erase(it);
            }
        }
        cout<<total<<endl;
        for(int i =0; i<n; i++)
        {
            cout<<wish[i]<<" ";
        }
        cout<<endl;
    }
}
