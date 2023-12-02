#include <iostream>
#include <math.h>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <cstdio>

using namespace std;

string S;
int N;
vector<int> prefix_sol,suffix_sol;
void build(vector<int> &sol)
{
    stack<char> active;
    for(int i = 0; i<N; i++)
    {
        sol[i+1]=sol[i];
        while(!active.empty()&&active.top()>S[i])
            active.pop();
        if(active.empty()||active.top()<S[i]){
            active.push(S[i]);
            sol[i+1]++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int Q, i,j;
    cin>>N>>Q>>S;
    prefix_sol.resize(N+1);
    suffix_sol.resize(N+1);
    build(prefix_sol);
    reverse(S.begin(),S.end());
    build(suffix_sol);
    for(int q = 0; q<Q; q++)
    {
        cin>>i>>j;
        cout<<prefix_sol[i-1]+suffix_sol[N-j]<<endl;
    }
}
