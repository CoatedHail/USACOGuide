
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
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> desire;
    for(int i = 0; i<n; i++)
    {
        int num;
        cin>>num;
        desire.push_back(num);
    }
    vector<int> size;
    for(int i = 0; i<m; i++)
    {
        int num;
        cin>>num;
        size.push_back(num);
    }
    sort(desire.begin(),desire.end());
    sort(size.begin(),size.end());
    int curr = 0;
    int ans = 0;
    for(int i = 0; i<n; i++)
    {
        while(curr<m) {
            if (abs(size[curr] - desire[i]) <= k) {
                ans++;
                curr++;
                break;
            } else if (size[curr] > desire[i])
                break;
            curr++;
        }

    }
    cout<<ans;
}
