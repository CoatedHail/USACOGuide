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
        string s;
        cin>>s;
        int maxSortedPref = 0;
        int minNotSortedPref = 0;
        int bal = 0;
        bool good = true;

        for (auto c : s) {
            if (c == '+') {
                ++bal;
            } else if (c == '-') {
                --bal;
                maxSortedPref = min(maxSortedPref, bal);
                if (bal < minNotSortedPref)
                    minNotSortedPref = 0;
            } else if (c == '1') {
                maxSortedPref = max(maxSortedPref, bal);
            } else {
                if (bal <= 1) {
                    good = false;
                    break;
                }
                if (minNotSortedPref == 0 || minNotSortedPref > bal)
                    minNotSortedPref = bal;
            }
            if(minNotSortedPref <= maxSortedPref && minNotSortedPref != 0) {
                good = false;
                break;
            }
        }

        if (good)
            puts("YES");
        else
            puts("NO");
    }
}
