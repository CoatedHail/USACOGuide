#include <iostream>
#include <math.h>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <set>
#include <unordered_map>
#include <iomanip>
#include <cstdio>

using namespace std;

const int mod = 1e9+7;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long t;
    cin>>t;
    while(t--)
    {
        long long n,m,k;
        cin>>n>>m>>k;
        bool works = true;
        vector<long long> a(k);
        for(int i =0; i<k; i++)
            cin>>a[i];
        priority_queue<long long> pq;
        long long slots = (n*m)-3;
        long long curr = k;
        for(int i =0; i<k; i++)
        {
            while(!pq.empty()&&pq.top()==curr&&curr)
            {
                pq.pop();
                curr--;
            }
            if(!curr)break;
            if(curr!=a[i]){
                pq.push(a[i]);
            }
            else
                curr--;
            if(pq.size()>=slots)
            {
                works = false;
                break;
            }
        }
        if(works&&pq.size()<slots)
            cout<<"YA"<<endl;
        else
            cout<<"TIDAK"<<endl;
    }
}
