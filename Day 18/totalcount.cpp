#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int totalCount(int k, vector<int>& arr) {
        int n = arr.size();
        int total_count = 0;
        for(int i=0;i<n;i++){
            total_count += (arr[i] + k - 1) / k;
        }
        return total_count;
    }
};

int main(){
    int k = 3;
    vector<int> arr = {5,8,10,13};
    Solution sol;
    cout<<sol.totalCount(k,arr)<<endl;
    return 0;
}