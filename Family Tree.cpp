#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"
#include "set"
#include "unordered_set"
#include "stack"
#include "map"
#include "limits.h"
#include "cstdio"
#include "math.h"
#include <iomanip>
#include <numeric>
using namespace std;

int n;
int MAXN = 101;
vector<string> daughter(MAXN);
vector<string> mother(MAXN);

string findm(string cow)
{
    for(int i = 0; i<n; i++)
    {
        if(cow == daughter[i])
            return mother[i];
    }
    return "";
}

int ancestor(string cow1, string cow2)
{
    int count = 0;
    while(cow2!="")
    {
        if(cow1==cow2)
            return count;
        cow2 = findm(cow2);
        count++;
    }
    return -1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("family.in", "r", stdin);
    freopen("family.out", "w", stdout);
    string bessie,elsie;
    cin>>n>>bessie>>elsie;
    for(int i =0; i<n; i++)
    {
        cin>>mother[i]>>daughter[i];
    }
    string cow = bessie;
    int b = 0;
    while(cow!="")
    {
        if(ancestor(cow,elsie)!=-1)
            break;
        cow = findm(cow);
        b++;
    }
    if(cow=="")
    {
        cout<<"NOT RELATED";
        return 0;
    }
    int a = ancestor(cow,elsie);
    if(a==1&&b==1)
        cout<<"SIBLINGS";
    else if(a>1&&b>1)
        cout<<"COUSINS";
    else
    {
        if(a>b) {
            swap(elsie, bessie);
            swap(a,b);
        }
        cout<<elsie<<" is the ";
        for(int i = 0; i<b-2; i++)
            cout<<"great-";
        if(b>1&&a==0)
            cout<<"grand-";
        if(a==0)
            cout<<"mother";
        else
            cout<<"aunt";
        cout<<" of "<<bessie;
    }
}
