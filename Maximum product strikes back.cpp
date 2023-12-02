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
    while(t--) {
        int n;
        cin>>n;
        vector<int> v(n);
        int ans = 0;
        for(int i =0; i<n; i++)
        {
            cin>>v[i];
        }
        int ap = n;
        int as = 0;
        for(int i =0, l = -1; i<=n; i++)
        {
            if(i==n||v[i]==0)
            {
                int count = 0;
                bool neg = false;
                int left = -1, right = -1;
                int cl = 0, cr = 0;
                for(int j = l+1; j<i; j++) {
                    neg ^= v[j] < 0;
                    if (v[j] < 0)
                    {
                        right = j;
                        cr = 0;
                    }
                    if(abs(v[j])==2)
                    {
                        count++;
                        cr++;
                        if(left == -1)
                            cl++;
                    }
                    if(v[j]<0&&left ==-1){
                        left = j;
                    }
                }
                if(neg)
                {
                    if(count-cl>count-cr)
                    {
                        right = i;
                        count-=cl;
                    }else
                    {
                        left = l;
                        count-=cr;
                    }
                }
                else
                {
                    left = l, right = i;
                }
                if(ans<count)
                {
                    ans = count;
                    ap = left+1, as = n-right;
                }
                l = i;
            }
        }
        cout<<ap<<" "<<as<<endl;
    }
}
