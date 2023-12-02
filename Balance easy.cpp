#include <iostream>
#include <math.h>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>
#include <cstdio>

using namespace std;

const int mod = 1e9+7;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int q;
    cin>>q;
    unordered_set<long long> xs;
    unordered_map<long long,long long> prev;
    while(q--)
    {
        char op;
        cin>>op;
        long long num;
        cin>>num;
        if(op=='+')
            xs.insert(num);
        else
        {
            if(!prev.count(num))
            {
                long long count = num;
                while(xs.count(count))
                    count+=num;
                cout<<count<<endl;
                prev[num]=count;
            }
            else
            {
                long long count = prev[num];
                while(xs.count(count))
                    count+=num;
                cout<<count<<endl;
                prev[num]=count;
            }
        }
    }
}
