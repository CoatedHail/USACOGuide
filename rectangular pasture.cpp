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

bool ycompress(pair<int,int> a, pair<int,int> b){
    return a.second < b.second;
}

int total(vector<vector<int>>& matrix, int x1, int y1, int x2, int y2){
    return matrix[x2][y2] - matrix[x2][y1 - 1] - matrix[x1 - 1][y2] + matrix[x1 - 1][y1 - 1];
}

int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> cows(n);
    for (int i = 0; i < n; i++){
        cin >> cows[i].first >> cows[i].second;
    }
    vector<vector<int>> matrix(n + 1, vector<int>(n + 1, 0));
    long long ans = 0;
    sort(cows.begin(),cows.end());
    for (int i = 0; i < n; i++)
        cows[i].first = i;
    sort(cows.begin(),cows.end(),ycompress);
    for (int i = 0; i < n; i++)
        cows[i].second = i;
    for (int i = 0; i < n; i++)
        matrix[cows[i].first + 1][cows[i].second + 1] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            matrix[i][j] += matrix[i - 1][j] + matrix[i][j - 1] - matrix[i - 1][j - 1];
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++){
            int left = min(cows[i].first, cows[j].first)+1;
            int right = max(cows[i].first, cows[j].first)+1;
            ans += total(matrix, 1, i + 1, left, j + 1) * total(matrix, right, i + 1, n, j + 1);
        }
    cout << ans + 1;

    return 0;
}