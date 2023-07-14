//
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

struct Cow {
    int weight;
    int pos;
    int speed;
};
bool cmp(Cow a, Cow b)
{
    return a.pos<b.pos;
}
bool cmp2(pair<int,int> a, pair<int,int> b)
{
    return a.first<b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("meetings.in", "r", stdin);
    freopen("meetings.out", "w", stdout);
    int n,l;
    cin>>n>>l;
    vector<Cow> cows(n);
    int total_weight = 0;
    for (Cow &c : cows) {
        cin>> c.weight >> c.pos >> c.speed;
        total_weight += c.weight;
    }
    sort(cows.begin(),cows.end(), cmp);
    vector<Cow> left;
    vector<Cow> right;
    for (const Cow &c : cows) {
        if (c.speed == -1) {
            left.push_back(c);
        } else if (c.speed == 1) {
            right.push_back(c);
        }
    }
    vector<pair<int, int>> weight_times;
    for (int c = 0; c < left.size(); c++) {
        weight_times.push_back({left[c].pos, cows[c].weight});
    }
    for (int c = 0; c < right.size(); c++) {
        weight_times.push_back(
                {l - right[c].pos, cows[left.size() + c].weight});
    }
    std::sort(weight_times.begin(), weight_times.end(),cmp2);

    int endTime = -1;
    for (const auto &[time, weight] : weight_times) {
        total_weight -= 2 * weight;
        if (total_weight <= 0) {
            endTime = time;
            break;
        }
    }
    int meeting_num = 0;
    queue<int> leftSide;
    for (int c = 0; c < n; c++) {
        if (cows[c].speed == 1) {
            leftSide.push(cows[c].pos);
        } else if (cows[c].speed == -1) {
            while (!leftSide.empty() &&
                   leftSide.front() + 2 * endTime < cows[c].pos) {
                leftSide.pop();
            }
            meeting_num += leftSide.size();
        }
    }
    cout<<meeting_num;
}
