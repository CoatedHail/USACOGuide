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
        int n;
        cin>>n;
        if(n<4) {
            cout << -1<<endl;
            continue;
        }
        for(int i = n; i>=1; i--)
        {
            if(i%2==1)
                cout<<i<<" ";
        }
        cout<<4<<" "<<2<<" ";
        for(int i = 6; i<=n; i++)
        {
            if(i%2==0)
                cout<<i<<" ";
        }
        cout<<endl;
    }

}