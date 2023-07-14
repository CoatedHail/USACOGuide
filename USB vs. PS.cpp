
#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"
#include "set"
#include "stack"
#include "map"
#include "limits.h"
#include "cstdio"
#include "math.h"
#include <iomanip>
#include <numeric>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int usb,ps,both;
    cin>>usb>>ps>>both;
    int m;
    cin>>m;
    vector<long long> ucost,pcost;
    for(int i = 0; i<m; i++)
    {
        long long cost;
        string type;
        cin>>cost>>type;
        if(type == "USB")
            ucost.push_back(cost);
        else
            pcost.push_back(cost);
    }
    long long ans = 0;
    sort(ucost.begin(),ucost.end());
    sort(pcost.begin(),pcost.end());
    long long curru,currp;
    curru=currp=0;
    long long count = 0;
    while(usb>0&&curru<ucost.size())
    {
        ans+=ucost[curru];
        curru++;
        usb--;
        count++;
    }
    while(ps>0&&currp<pcost.size())
    {
        ans+=pcost[currp];
        currp++;
        ps--;
        count++;
    }
    while(both>0&&(curru<ucost.size()||currp<pcost.size()))
    {
        if(currp==pcost.size())
        {
            while(curru<ucost.size()&&both>0)
            {
                ans+=ucost[curru];
                count++;
                curru++;
                both--;
            }
            cout<<count<<" "<<ans;
            return 0;
        }
        else if(curru==ucost.size())
        {
            while(currp<pcost.size()&&both>0)
            {
                ans+=pcost[currp];
                count++;
                currp++;
                both--;
            }
            cout<<count<<" "<<ans;
            return 0;
        }
        else if(pcost[currp]>ucost[curru])
        {
            ans+=ucost[curru];
            curru++;
        }
        else
        {
            ans +=pcost[currp];
            currp++;
        }
        both--;
        count++;
    }
    cout<<count<<" "<<ans;
}