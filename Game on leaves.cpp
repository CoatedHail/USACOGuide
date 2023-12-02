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
        int n,x;
        cin>>n>>x;
        vector<int> degree(n+1,0);
        for(int i = 1; i<=n-1; i++)
        {
            int u,v;
            cin>>u>>v;
            degree[u]++;
            degree[v]++;
        }
        if(degree[x]<=1)
            cout<<"Ayush"<<endl;
        else
        {
            if(n%2)
                cout<<"Ashish"<<endl;
            else
                cout<<"Ayush"<<endl;
        }
    }

}
