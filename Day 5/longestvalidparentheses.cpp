#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int maxLength(string str) {
        int n = str.length();
        int close = 0;
        int open = 0;
        int ans = 0;
        //check for left to right
        for(int i=0;i<n;i++){
            if(str[i] == '('){
                open++;
            }
            if(str[i] == ')'){
                close++;
            }
            if(close > open){
                open = 0;
                close = 0;
            }
            if(open == close){
                ans = max(ans,open + close);
            }
        }
        
        open = 0;
        close = 0;
        // check for right to left
        for(int i=n-1;i>=0;i--){
            if(str[i] == '('){
                open ++;
            }
            if(str[i] == ')'){
                close ++;
            }
            if(open > close){
                open = 0;
                close = 0;
            }
            if(open == close){
                ans = max(ans,open+close);
            }
        }
        return ans;
    }
};
int main(){
    string s;
    cin>>s;
    Solution obj;
    int ans = obj.maxLength(s);
    cout<<ans<<endl;
    return 0;
}