#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void solve(int idx,string s,vector<string> &s_ans,vector<vector<string>> &f_ans){
//         we push only if for all previous string in set partition goe till end
        if(idx==s.size()){
            f_ans.push_back(s_ans);
            return;
        }
// starting from 1st cut we go deeper then we go back start from 2nd and go back and so on
        for(int i=idx;i<s.size();i++){
//             check if its palindrome
            if(is_pal(s,idx,i)){
                s_ans.push_back(s.substr(idx,i-idx+1));
                solve(i+1,s,s_ans,f_ans);
//                 whe we are coming back we want to pop
                s_ans.pop_back();
            }
            
            
        }
        
            
    }
    
    bool is_pal(string s,int start,int end){
        while(start<end){
            if(s[start]!=s[end]){
                return false;
          
            }
                 start++;
                end--;
            
        }
        return true;
    }
    
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> f_ans;
        vector<string> s_ans;
        solve(0,s,s_ans,f_ans);
        
        return f_ans;
        
        

        
        
        
    }
};