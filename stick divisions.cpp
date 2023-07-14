
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
    int x,n;
    cin>>x>>n;
    priority_queue<long long,vector<long long>, greater<long long>> divi;
    for(int i = 0; i<n; i++) {
        int num;
        cin >> num;
        divi.push(num);
    }
    long long total=0;
    for(int i =1; i<n; i++)
    {
        long long a,b;
        a = divi.top();
        divi.pop();
        b = divi.top();
        divi.pop();
        divi.push(a+b);
        total+=a+b;
    }
    cout<<total;
}