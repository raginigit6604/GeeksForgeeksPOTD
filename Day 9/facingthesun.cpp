#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int countBuildings(vector<int> &height) {
        if(height.empty()){
            return 0;
        }
        int count = 1; // here we intialize count = 1 because first building always see the sunrise
        int max_height = height[0]; // here we track the maximum height
        
        for(int i=0;i<height.size();i++){
            if(height[i] > max_height){
                count++; //so this building can see the sunrise
                max_height = height[i]; //here i update the maximum height
            }
        }
        return count;
    }
};
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Solution sol;
    cout<<sol.countBuildings(arr)<<endl;
    return 0;
}