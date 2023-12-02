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
        long long n;
        cin>>n;
        string s;
        cin>>s;
        vector<int> bal(n+1);
        for(int i = 0; i<n; i++)
        {
            if(s[i]=='(')
                bal[i+1]=bal[i]+1;
            else
                bal[i+1]=bal[i]-1;
        }
        if(bal.back()!=0)
            cout<<-1<<endl;
        else
        {
            if(*min_element(bal.begin(),bal.end())==0||*max_element(bal.begin(),bal.end())==0)
            {
                cout<<1<<endl;
                for(int i = 0; i<n; i++)
                {
                    if(i) cout<<" ";
                    cout<<1;
                }
                cout<<endl;
            }
            else
            {
                cout<<2<<endl;
                vector<int> ans;
                int cur = 0;
                while(cur<n)
                {
                    int w;
                    if(s[cur]=='(')
                        w = 2;
                    else
                        w = 1;
                    do
                    {
                        cur++;
                        ans.push_back(w);
                    }
                    while(bal[cur]!=0);
                }
                for(int i = 0; i<n; i++)
                {
                    if(i) cout<<" ";
                    cout<<ans[i];
                }
                cout<<endl;
            }
        }
    }
}
