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
    int tests;
    cin>>tests;
    while(tests--) {
        vector<string> s(2);
        cin>>s[0]>>s[1];
        int size = s[1].size();
        int t,q;
        cin>>t>>q;
        int bad=0;
        for(int i = 0; i<size; i++)
            if(s[0][i]!=s[1][i])
                bad++;
        queue<pair<int,int>> unblock;
        for(int i = 0; i<q; i++)
        {
            while(!unblock.empty()&&unblock.front().first==i)
            {
                if(s[0][unblock.front().second]!=s[1][unblock.front().second])
                    bad++;
                unblock.pop();
            }
            int type;
            cin>>type;
            if(type == 1)
            {
                int pos;
                cin>>pos;
                if(s[0][pos-1]!=s[1][pos-1])
                    bad--;
                unblock.push(make_pair(i+t,pos-1));
            }
            else if(type == 2)
            {
                int num1,pos1,num2,pos2;
                cin>>num1>>pos1>>num2>>pos2;
                num1--;
                pos1--;
                pos2--;
                num2--;
                if(s[num1][pos1]!=s[(num1+1)%2][pos1])
                    bad--;
                if(s[num2][pos2]!=s[(num2+1)%2][pos2])
                    bad--;
                swap(s[num1][pos1],s[num2][pos2]);
                if(s[num1][pos1]!=s[(num1+1)%2][pos1])
                    bad++;
                if(s[num2][pos2]!=s[(num2+1)%2][pos2])
                    bad++;
            }
            else
            {
                if(bad)
                    cout<<"NO\n";
                else
                    cout<<"YES\n";
            }
        }
    }
}

