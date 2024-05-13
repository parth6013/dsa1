// Subset 2 leetcode

// brute

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void solve(vector<int> &nums,int i,int n,set<vector<int>> &p,vector<int> ans){
        
        if(i==n){
            sort(ans.begin(),ans.end());
            p.insert(ans);
            return;
        }
        
//   dont take the element
        solve(nums,i+1,n,p,ans);
        
//   take the element
        ans.push_back(nums[i]);
        solve(nums,i+1,n,p,ans);
        
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<int> ans;
        vector<vector<int>> f_ans;
        set<vector<int>> p;
        
        solve(nums,0,nums.size(),p,ans);
        
        for(auto x : p){
            f_ans.push_back(x);
        }
        
        return f_ans;
        
    }
};

// optimised

class Solution {
public:
    
    void solve(vector<vector<int>> &f_ans,vector<int> &sub_ans,vector<int>&nums,int ind){
        f_ans.push_back(sub_ans);
        for(int i=ind;i<nums.size();i++){
            if(i!=ind && nums[i]==nums[i-1]) continue;
            sub_ans.push_back(nums[i]);
            solve(f_ans,sub_ans,nums,i+1);
            sub_ans.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> f_ans;
        vector<int> sub_ans;
//         we want to skip two same numbers as different vector
        sort(nums.begin(),nums.end());
        solve(f_ans,sub_ans,nums,0);
        
        return f_ans;
    }
};