#include<bits/stdc++.h>
using namespace std;

// Brute force O(n^2) method


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
    string ans=strs[0];
        
        for(int i=1;i<strs.size();i++){
                string c_ans="";       
            for(int j=0;j<strs[i].size();j++){
                if(strs[i][j]==ans[j]){
                    c_ans=c_ans+ans[j];
                    // cout<<
                }else{
                    ans=c_ans;
                    break;
                }
            }
            if(c_ans.size()<ans.size()){
                ans=c_ans;
            }
        }
        
        
        return ans;
        
        
    }
};


//  if we sort the array the most difference will be in first word and last word we use this for our info


class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        int n = str.size();
        if(n==0) return "";
        
        string ans  = "";
        sort(begin(str), end(str));
        string a = str[0];
        string b = str[n-1];
        
        for(int i=0; i<a.size(); i++){
            if(a[i]==b[i]){
                ans = ans + a[i];
            }
            else{
                break;
            }
        }
        
        return ans;
        
    }
};