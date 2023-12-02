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

long long gcd(long long a, long long b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    cin >> n;
    vector<long long> coprime;
    for(int i = 1; i<n; i++)
    {
        if(gcd(n,i)==1)
            coprime.push_back(i);
    }
    int numco = coprime.size();
    vector<long long> prefix(numco);
    prefix[0]=1;
    for(int i = 1; i<numco; i++)
    {
        prefix[i]=(prefix[i-1]*coprime[i])%n;
    }
    int length = 1;
    for(int i = 0; i<numco; i++)
    {
        if(prefix[i]==1)
        {
            length = i+1;
        }
    }
    cout<<length<<endl;
    for(int i = 0; i<length; i++)
    {
        cout<<coprime[i]<<" ";
    }
}