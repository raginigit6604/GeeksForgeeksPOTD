#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int maxStep(vector<int>& arr) {
        int n = arr.size();
        int count = 0;
        int max_steps = 0;
        for(int i=0;i<n-1;i++){
            if(arr[i]<arr[i+1]){
                count += 1;
            }
            else{
                max_steps = max(max_steps,count);
                count = 0;
            }
        }
        max_steps = max(max_steps,count);
        return max_steps;
    }
};
int main(){
    vector<int> arr = {1,2,2,3,2};
    Solution s;
    cout<<s.maxStep(arr)<<endl;
    return 0;
}