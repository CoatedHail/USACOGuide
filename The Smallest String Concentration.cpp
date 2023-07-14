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


bool cmp(string a, string b){
    return (a+b<b+a);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin>>n;
    vector<string> ls;
    for (int i = 0; i< n; i++){
        string tmp; cin>>tmp;
        ls.push_back(tmp);
    }
    sort(ls.begin(), ls.end(), cmp);
    string a;
    for (int i= 0; i< n; i++){
        a+=ls[i];
    }
    cout<<a<<endl;
    return 0;
}