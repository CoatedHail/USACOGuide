
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
    int n, x;
    cin>>n>>x;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int sum= 0, ans = 0;
    int left = 0;
    for(int right=0; right<n; right++){
        sum += arr[right];
        while(sum>x){
            sum -= arr[left];
            left++;
        }
        if(sum==x) ans++;
    }
    cout<<ans;
}
