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

int ask(int x, int y) {
    cout << "? " << x + 1 << ' ' << y + 1 << endl;
    int z;
    cin >> z;
    return z;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> ans(n,-1);
    int mx = 0;
    for(int i = 1; i<n; i++)
    {
        int a = ask(mx,i);
        int b = ask(i,mx);
        if(a>b)
        {
            ans[mx]=a;
            mx = i;
        }
        else
            ans[i]=b;
    }
    ans[mx]=n;
    cout<<"! ";
    for(int i = 0; i<n; i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}
