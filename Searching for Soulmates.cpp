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

long long solve(long long a, long long b)
{
    if(a==b)
        return 0;
    else if(a>b)
    {
        long long odd = a%2;
        return 1+odd+solve((a+odd)/2,b);
    }
    else
    {
        long long odd = b%2;
        return min(b-a,1+odd+solve(a,(b)/2));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i = 0; i<n; i++)
    {
        long long a,b;
        cin>>a>>b;
        cout<<solve(a,b);
    }
}