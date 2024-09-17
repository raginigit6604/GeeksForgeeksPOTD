#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
     int n = arr.size();
      if (n == 1){ // if we have only one elemnts
          return 0;
      }
      sort(arr.begin(),arr.end());
      int difference = arr[n-1] - arr[0];
      int small = arr[0] + k;
      int large = arr[n-1] - k;
      for(int i=1;i<=n;i++){
          if(arr[i]>=k){
            int min_value = min(small,arr[i] - k);
            int max_value = max(large,arr[i-1] + k);
            difference = min(difference, max_value - min_value);
          }
      }
      return difference;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> arr1 = {1, 5, 8, 10};
    int k1 = 2;
    cout << "Minimum difference (Test Case 1): " << sol.getMinDiff(arr1, k1) << endl;  // Output: 5

    // Test Case 2
    vector<int> arr2 = {3, 9, 12, 16, 20};
    int k2 = 3;
    cout << "Minimum difference (Test Case 2): " << sol.getMinDiff(arr2, k2) << endl;  // Output: 11

    return 0;
}