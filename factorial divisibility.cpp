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



int main() {
    ios_base::sync_with_stdio(false);
    int n,x;
    cin>>n>>x;
    vector<int> count(x+1,0);
    for(int i = 0; i<n; i++)
    {
        int p;
        cin>>p;
        count[p]++;
    }
    bool works = true;
    for(int i = 1; i<x; i++)
    {
        if(!count[i]) continue;
        if(count[i] % (i+1)!=0)
        {
            cout<<"NO"<<endl;
            works = false;
            break;
        }
        count[i+1]+=count[i]/(i+1);
    }
    if(works)
        cout<<"YES"<<endl;
}
