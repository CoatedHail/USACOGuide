
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
    int n;
    cin>>n;
    string s;
    cin>>s;
    map<char,int> vis;
    for(int i=0;i<n;++i){
        cin>>s[i];
        vis[s[i]]++;
    }
    int tot=vis.size();
    vis.clear();
    int ans=n;
    for(int i=0,j=0;i<n;++i){
        while(j<n&&vis.size()<tot) vis[s[j++]]++;
        if(vis.size()==tot) ans=min(ans,j-i);
        if(!--vis[s[i]]) vis.erase(s[i]);
    }
    cout<<ans<<endl;
}
