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
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,Q;
    vector<long long> H,G,J;
    cin>>N>>Q;
    G.push_back(0);
    H.push_back(0);
    J.push_back(0);
    for(int i =0; i<N; i++)
    {
        int num;
        cin>>num;
        if(num==1)
        {
            H.push_back(H[i]+1);
            G.push_back(G[i]);
            J.push_back(J[i]);
        }
        else if(num==2)
        {
            G.push_back(G[i]+1);
            H.push_back(H[i]);
            J.push_back(J[i]);
        }
        else
        {
            G.push_back(G[i]);
            H.push_back(H[i]);
            J.push_back(J[i]+1);
        }
    }
    for(int i =0; i<Q; i++)
    {
        int a,b;
        cin>>a>>b;
        cout<<H[b]-H[a-1]<<" "<<G[b]-G[a-1]<<" "<<J[b]-J[a-1]<<endl;

    }

}
