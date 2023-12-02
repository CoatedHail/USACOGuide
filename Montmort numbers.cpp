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


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    int a = 1;
    int b = 0;
    cout<<0<<' ';
    for(int i = 2; i<=N; i++)
    {
        int c = (i-1)*(a+b)%M;
        cout<<c<<' ';
        a=b;
        b=c;
    }
}
