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


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("helpcross.in","r",stdin);
    freopen("helpcross.out","w",stdout);
    int c,n;
    cin>>c>>n;
    vector<int> chick(c);
    for(int i = 0; i<c; i++)
    {
        cin>>chick[i];
    }
    vector<pair<int,int>> cow(n);
    for(int i = 0; i<n; i++)
    {
        int a,b;
        cin>>a>>b;
        cow[i]=make_pair(a,b);
    }
    sort(chick.begin(),chick.end());
    sort(cow.begin(),cow.end());
    int currcow, currchick;
    currcow = currchick = 0;
    int totpairs=0;
    while(currcow<n&&currchick<c)
    {
        if(chick[currchick]>=cow[currcow].first&&chick[currchick]<=cow[currcow].second)
        {
            totpairs++;
            currcow++;
            currchick++;
        }
        else if(chick[currchick]<cow[currcow].first)
            currchick++;
        else if(chick[currchick]>cow[currcow].second)
        {
            currcow++;
        }
    }
    cout<<totpairs;
}
/*#include <iostream>
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


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("helpcross.in","r",stdin);
    //freopen("helpcross.out","w",stdout);
    int c, n;
    cin >> c >> n;
    multiset<int> chick;
    for (int i = 0; i < c; i++) {
        int num;
        cin >> num;
        chick.insert(num);
    }
    vector<pair<int, int>> cow(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        cow[i] = make_pair(b, a);
    }
    sort(cow.begin(), cow.end());
    int currcow, currchick;
    currcow = currchick = 0;
    int totpairs = 0;
    for (int i = 0; i < n; i++) {
        auto which = chick.lower_bound(cow[i].second);
        if (which != chick.end() && *which <= cow[i].first) {
            totpairs++;
            chick.erase(which);
        }
    }
    cout << totpairs;
}*/