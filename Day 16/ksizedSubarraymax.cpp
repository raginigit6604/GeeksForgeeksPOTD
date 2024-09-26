#include <vector>
#include <deque>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> max_of_subarrays(int k, vector<int>& arr) {
        vector<int> result;
        deque<int> dq; // Create a deque to store indices of useful elements

        for (int i = 0; i < arr.size(); i++) {
            // Remove elements that are out of this window
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Remove elements  that are smaller than the current element
            while (!dq.empty() && arr[dq.back()] <= arr[i]) {
                dq.pop_back();
            }

            // Add current element's index to the deque
            dq.push_back(i);

            // Starting from index k-1, we can start to output results
            if (i >= k - 1) {
                result.push_back(arr[dq.front()]); // The front of the deque is the maximum
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    int k = 3;
    vector<int> result = sol.max_of_subarrays(k, arr);

    for (int val : result) {
        cout << val << " ";
    }
    return 0;
}
