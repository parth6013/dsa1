// longest subsequence

#include<bits/stdc++.h>
using namespace std;























// brute recursice solution 2^n
class Solution {
public:
    
    void solve(int i,vector<int>&s_ans,vector<int>&nums,int &max1){
        
        
//         base case
        
        if(i==nums.size()){
            // cout<<s_ans[0]<<" ";
            for(int j=1;j<s_ans.size();j++){
                // cout<<s_ans[j]<<" ";
                if(s_ans[j-1]>s_ans[j]){
                    // cout<<endl;
                    return;
                }
            }
                if(s_ans.size()>max1){
                    max1=s_ans.size();
                }
            return;
        }
        
//        take that element
        
        s_ans.push_back(nums[i]);
        solve(i+1,s_ans,nums,max1);
        s_ans.pop_back();
        
//  dont take that element
        solve(i+1,s_ans,nums,max1);
        
    }
    
    int lengthOfLIS(vector<int>& nums) {
        vector<int> s_ans;
        int max1=1;
        solve(0,s_ans,nums,max1);
        
        return max1;
        
        
    }
};