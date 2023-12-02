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

bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<int> Jirodef,Jiroatk;
    int dcount,acount;
    dcount = acount = 0;
    vector<int> Ciel;
    for(int i = 0; i<n; i++)
    {
        string aord;
        int stre;
        cin>>aord>>stre;
        if(aord=="ATK") {
            Jiroatk.push_back(stre);
            acount++;
        }
        else {
            Jirodef.push_back(stre);
            dcount++;
        }
    }
    sort(Jiroatk.begin(),Jiroatk.end());
    sort(Jirodef.begin(),Jirodef.end());
    for(int i = 0; i<m; i++)
    {
        int stre;
        cin>>stre;
        Ciel.push_back(stre);
    }
    sort(Ciel.begin(),Ciel.end(),cmp);
    int curr=0;
    int max=0;
    int totuse=0;
    vector<bool> used(m,false);
    bool complete = false;
    int run = 0;
    for(int i = 0; i<acount; i++)
    {
        if(totuse==m)
        {
            cout<<max;
            return 0;
        }
        if(Ciel[curr]>=Jiroatk[i])
        {
            max+=Ciel[curr]-Jiroatk[i];
            totuse++;
            used[m-1-curr]=true;
            curr++;
        }
        else
            break;
        run++;
    }
    curr = 0;
    sort(Ciel.begin(),Ciel.end());
    int run2=0;
    for(int i = 0; i<dcount; i++)
    {
        if(totuse==m)
        {
            cout<<max;
            return 0;
        }
        if(used[curr]==true) {
            curr++;
            continue;
        }
        while(Ciel[curr]<= Jirodef[i])
        {
            curr++;
        }
        used[curr]=true;
        totuse++;
        curr++;
        run2++;
    }
    if(run ==acount&&run2==dcount)
        complete = true;
    if(complete) {
        for (int i = 0; i < m; i++) {
            if (used[i] == false)
                max += Ciel[i];
        }
    }
    cout<<max;
}