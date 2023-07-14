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


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(true)
    {
        int p,c;
        cin>>p>>c;
        if(p==1)
        {
            cout<<"YES"<<endl;
            continue;
        }
        if(p==0&&c==0)
            return 0;
        vector<vector<int>> adj;
        adj.resize(p);
        for(int i =0; i<c; i++)
        {
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        bool works = false;
        for(int i=0; i<p; i++)
        {
            if(adj[i].size()<=1) {
                cout << "YES" << endl;
                works = true;
                break;
            }
        }
        if(works ==false)
            cout<<"NO"<<endl;
    }
}