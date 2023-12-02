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
    long long t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> numc(n);
        int ans = 0;
        for(int i = 1; i<n; i++)
        {
            int num;
            cin>>num;
            num--;
            numc[num]++;
        }
        numc.push_back(1);
        sort(numc.begin(),numc.end(),greater<int>());
        while (!numc.empty() && numc.back() <= 0) numc.pop_back();
        n = numc.size();
        for(int i = 0; i<n; i++)
        {
            numc[i]=numc[i]-(n-i);
            ans++;
        }
        sort(numc.begin(),numc.end(),greater<int>());
        while (!numc.empty() && numc.back() <= 0) numc.pop_back();
        while(!numc.empty())
        {
            n = numc.size();
            int last = 0;
            for(int i = 0; i<n; i++)
            {
                if(numc[i]==numc[0])
                    last = i;
                else
                    break;
            }
            numc[last]--;
            for(int i = 0; i<n; i++)
                numc[i]--;
            ans++;
            while (!numc.empty() && numc.back() <= 0) {
                numc.pop_back();
            }
        }
        cout<<ans<<endl;
    }
}

