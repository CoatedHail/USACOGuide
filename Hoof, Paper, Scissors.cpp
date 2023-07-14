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
using namespace std;


int main()
{
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin>>N;
    vector<long long> H,P,S;
    H.push_back(0);
    P.push_back(0);
    S.push_back(0);
    for(int i = 0; i<N; i++)
    {
        char c;
        cin>>c;
        S.push_back(S[i]);
        P.push_back(P[i]);
        H.push_back(H[i]);
        if(c=='P')
        {
            S[i+1]+=1;
        }
        else if(c =='H')
        {
            P[i+1]+=1;
        }
        else
        {
            H[i+1]+=1;
        }
    }
    long long biggest = 0;
    for(int i = 2; i<=N; i++)
    {
        biggest = max(biggest, H[i-1]+(S[N]-S[i-1]));
        biggest = max(biggest, H[i-1]+(P[N]-P[i-1]));
        biggest = max(biggest, S[i-1]+(P[N]-P[i-1]));
        biggest = max(biggest, S[i-1]+(H[N]-H[i-1]));
        biggest = max(biggest, P[i-1]+(S[N]-S[i-1]));
        biggest = max(biggest, P[i-1]+(H[N]-H[i-1]));


    }
    biggest = max(biggest, H[N]);
    biggest = max(biggest, P[N]);
    biggest = max(biggest, S[N]);
    cout<<biggest;
}
