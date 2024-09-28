#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int minimizeCost(int k, vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, 1e9); 
        dp[0] = 0;  
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j <= k; ++j) {
                if (i - j >= 0) {
                    dp[i] = min(dp[i], dp[i - j] + abs(arr[i] - arr[i - j]));
                }
            }
        }
        return dp[n - 1];
    }
};

int main() {

    int k, n;
    cout << "Enter the number of jumps allowed (k): ";
    cin >> k;

    cout << "Enter the number of stones (n): ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the heights of the stones: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    Solution sol;
    int result = sol.minimizeCost(k, arr);

    cout << "The minimum cost to reach the last stone is: " << result << endl;

    return 0;
}
