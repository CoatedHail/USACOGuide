#include <iostream>
#include <math.h>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cstdio>

using namespace std;

void solve() {
    int M, N, K;
    cin >> M >> N >> K;
    vector<vector<int>> folderemail(M);
    vector<vector<int>> filetime(M);
    vector<bool> filled(N);
    vector<bool> skip(N);
    vector<bool> inwin(N);
    vector<int> emailfold(N);
    for (int i = 0; i < N; i++) {
        cin >> emailfold[i];
        filetime[max(0, --emailfold[i] - K + 1)].push_back(i);
        folderemail[emailfold[i]].push_back(i);
    }
    int curremail = 0;
    int lhsemail = 0;
    int numinwind = 0;
    int rhemail = N - 1;
    auto fileemail = [&](int id) -> void {
        if (inwin[id]) {
            inwin[id] = false;
            numinwind--;
        }
        filled[id] = true;
    };
    int bottom = 0;
    for(int i = 0; i<M; i++)
    {
        if(i>bottom &&i+K<=M) bottom++;
        for(int out: filetime[i])
            if(inwin[out])
                fileemail(out);
        while(folderemail[i].size()&&curremail<=folderemail[i].back())
        {
            if(numinwind==K)
            {
                while(!inwin[lhsemail])
                    lhsemail++;
                skip[lhsemail] = true;
                inwin[lhsemail]=false;
                numinwind--;
            }
            if(emailfold[curremail]>=i&& emailfold[curremail]<=i+K-1)
            {
                filled[curremail++]=true;
                continue;
            }
            inwin[curremail++]=true;
            numinwind++;
        }
        while(curremail<N&&numinwind<K)
        {
            if(emailfold[curremail]>=i&&emailfold[curremail]<=i+K-1)
            {
                filled[curremail++]=true;
                continue;
            }
            inwin[curremail++]=true;
            numinwind++;
        }
        if(curremail==N)
        {
            while(numinwind<K)
            {
                if(rhemail<0) break;
                if(!skip[rhemail])
                {
                    rhemail--;
                    continue;
                }
                if(emailfold[rhemail]<bottom)
                {
                    cout<<"NO\n";
                    return;
                }
                if(emailfold[rhemail]<=bottom+K-1)
                {
                    filled[rhemail--]=true;
                    continue;
                }
                inwin[rhemail--]=true;
                numinwind++;
            }
        }
    }
    for(auto out:filled)
    {
        if(!out)
        {
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
        solve();
}
