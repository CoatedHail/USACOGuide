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
#include <numeric>
using namespace std;

int nondec(const vector<int> &seq) {
    vector<int> min_endings;
    for (int i : seq) {
        int pos = upper_bound(min_endings.begin(), min_endings.end(), i) - min_endings.begin();
        if (pos == min_endings.size()) {
            min_endings.push_back(i);
        } else {
            min_endings[pos] = i;
        }
    }
    return min_endings.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<int> seq;
    for(int i = 0; i<n; i++)
    {
        int num;
        cin>>num;
        seq.push_back(num);
    }
    vector<int> unchanged;
    for(int i = 1; i<=n; i++)
    {
        if(i*m>=seq[i-1])
        {
            unchanged.push_back(i*m-seq[i-1]);
        }
    }
    cout<<n-nondec(unchanged);
}
