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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    cin.ignore(1000,'\n');
    string s;
    getline(cin,s);
    int l =1; int r= 1e6;
    while(l<r)
    {
        int mid = (l+r)/2;
        bool works = true;
        int count = 0;
        for(int i = 0; i<s.size(); i++)
        {
            int prev = i;
            i = min(i+mid-1,(int)s.size()-1);
            if(i==s.size()-1)
            {
                count++;
                break;
            }
            while(i>=prev&&s[i]!=' '&&s[i]!='-')
            {
                i--;
            }
            if(i==prev-1)
            {
                works = false;
                break;
            }
            count++;
        }
        if(works&&count<=n)
            r = mid;
        else
            l = mid+1;
    }
    cout<<l;
}