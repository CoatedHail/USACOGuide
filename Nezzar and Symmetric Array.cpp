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

int main() {
    int num;
    cin>>num;
    for(int i = 0; i<num; i++)
    {
        bool works = true;
        long long n;
        cin >> n;
        vector<long long> arr(2 * n);
        for (int j = 0; j < 2 * n; j++)
            cin >> arr[j];
        sort(arr.begin(), arr.end(), greater<long long>());
        set<long long> nums;
        long long sum = 0;
        for (long long j = 0; j < 2 * n; j += 2) {
            long long x = (arr[j] - sum) / (2 * n - j);
            if (arr[j] != arr[j + 1] || (arr[j] - sum) % (2 * n - j) != 0 || nums.count(x) || x < 1) {
                cout << "NO" << endl;
                works = false;
                break;

            }
            nums.insert(x);
            sum += 2 * x;
        }
        if(works==true)
            cout << "YES" << endl;
    }
}
