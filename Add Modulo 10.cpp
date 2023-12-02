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
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i = 0; i<n; i++)
            cin>>v[i];
        bool works = false;
        for(int i = 0; i<n; i++)
        {
            if(v[i]%5==0) {
                works = true;
                v[i] = v[i] + v[i] % 10;
            }
        }
        if(works)
        {
            if(min_element(v.begin(),v.end())==max_element(v.begin(),v.end()))
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
        else
        {
            bool flag2 = false, flag12 = false;
            for(int i = 0; i<n; i++)
            {
                int x = v[i];
                while(x%10!=2)
                    x+=x%10;
                if(x%20==2)
                    flag2 = true;
                else
                    flag12 = true;
            }
            if(flag2&&flag12)
                cout<<"NO";
            else
                cout<<"YES";
            cout<<endl;
        }
    }
}
