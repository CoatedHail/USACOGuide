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
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int c = 1;
        vector<char> s(n+1);
        while((n%c)==0) c++;
        for(int i = 0; i<n; i++)
            s[i]='a'+(i%c);
        s[n]='\0';
        for(int i = 0; i<n; i++)
            cout<<s[i];
        cout<<endl;
    }
}
