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
        int n, U,R,D,L;
        cin>>n>>U>>R>>D>>L;
        bool works = false;
        for(int i = 0; i<16; i++)
        {
            int ru = U, rr = R, rd = D, rl = L;
            if(i&1)
            {
                ru--;
                rl--;
            }
            if(i&2)
            {
                rl--;
                rd--;
            }
            if(i&4)
            {
                rd--;
                rr--;
            }
            if(i&8)
            {
                rr--;
                ru--;
            }
            if(min({ru,rl,rr,rd})>=0&&max({ru,rl,rr,rd})<=n-2)
            {
                cout<<"YES";
                works =true;
                break;
            }
        }
        if(!works)
            cout<<"NO";
        cout<<endl;
    }
}
