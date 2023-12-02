#include <iostream>
#include <math.h>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cstdio>

using namespace std;

vector<vector<vector<vector<long long>>>> dp(19,vector<vector<vector<long long>>>(50,vector<vector<long long>>(2,vector<long long>(2))));
string num;
void reset()
{
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 50; j++) {
            for (int k = 0; k < 2; k++) {
                for (int l = 0; l < 2; l++) { dp[i][j][k][l] = -1; }
            }
        }
    }
}

long long solve(int pos, int k, bool under, bool started, int targ, int targ2)
{
    if(pos==num.size())
    {
        if(!started)return 0;
        if(targ2!=-1)
        {
            if(k==20)
                return 1;
            else
                return 0;
        }
        if (k >= 20) {
            return 1;
        } else {
            return 0;
        }
    }
    if(dp[pos][k][under][started]!=-1) return dp[pos][k][under][started];
    long long ans = 0;
    for(int i = 0; i<=9; i++)
    {
        int digitdiff = num[pos]-'0';
        if(!under&&i>digitdiff)
            break;
        bool isunder = under;
        if(i<digitdiff)
            isunder = true;
        bool isstart = started ||i!=0;
        if(isstart&&targ2!=-1&&i!=targ&&i!=targ2)continue;

        int newk = k;
        if(isstart)
        {
            if(targ == i)
                newk=k+1;
            else
                newk=k-1;
        }
        ans+=solve(pos+1,newk,isunder,isstart,targ,targ2);
    }
    return dp[pos][k][under][started]=ans;
}

long long interesting(long long top)
{
    num = to_string(top);
    long long ans = 0;
    for(int i = 0; i<=9; i++)
    {
        reset();
        ans+=solve(0,20,false,false,i,-1);
    }
    long long duplicates = 0;
    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            reset();
            duplicates += solve(0, 20, false, false, i, j);
        }
    }
    return ans -(duplicates/2);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("odometer.in", "r", stdin);
    freopen("odometer.out", "w", stdout);
    long long X,Y;
    cin>>X>>Y;
    cout<<interesting(Y)-interesting(X-1);
}