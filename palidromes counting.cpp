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
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        vector<int> count(26);
        for(char c: s)
            count[c-'a']++;
        int pairs = 0,odd = 0;
        for(int c : count) {
            pairs += c / 2;
            odd+=c%2;
        }
        int ans = 2*(pairs/k);
        odd+=2*(pairs%k);
        if(odd>k)
            ans++;
        cout<<ans<<endl;
    }
}
