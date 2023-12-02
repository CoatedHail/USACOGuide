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
    while(t--) {
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i = 0; i<n; i++)
            cin>>v[i];
        int start =0 ;
        if(n%2==1)
        {
            if(v[0]+v[1]!=0)
            {
                cout<<-1*v[2]<<" "<<-1*v[2]<<" "<<v[0]+v[1]<<" ";
            }
            else if(v[1]+v[2]!=0)
            {
                cout<<v[2]+v[1]<<" "<<-1*v[0]<<" "<<-1*v[0]<<" ";
            }
            else
                cout<<-1*v[1]<<" "<<v[0]+v[2]<<" "<<-1*v[1]<<" ";
            start = 3;
        }
        while(start<n)
        {
            cout<<-v[start+1]<<" "<<v[start]<<" ";
            start+=2;
        }
        cout<<endl;
    }
}
