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

struct cmp {
    bool operator() (const pair<int, int> &a, const pair<int, int> &b) const {
        int lena = a.second - a.first + 1;
        int lenb = b.second - b.first + 1;
        if (lena == lenb) return a.first < b.first;
        return lena > lenb;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        set<pair<int,int>,cmp> segs;
        segs.insert({0,n-1});
        vector<int> a(n);
        for(int i = 1; i<=n; i++)
        {
            pair<int,int> curr=*segs.begin();
            segs.erase(segs.begin());
            int id = (curr.first+curr.second)/2;
            a[id]=i;
            if(curr.first<id)
            {
                segs.insert({curr.first,id-1});
            }
            if(id<curr.second)
                segs.insert({id+1,curr.second});
        }
        for(auto it: a)
            cout<<it<<" ";
        cout<<endl;
    }
}
