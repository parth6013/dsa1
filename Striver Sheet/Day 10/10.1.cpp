//  all possible permutation

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void solve(int idx, vector<int> nums,vector<vector<int>> &f_ans){
        
        if(idx==nums.size()){
            // for(int j=0;j<nums.size();j++){
            //     cout<<nums[j];
            // }
            // cout<<endl;
            f_ans.push_back(nums);
            return;
        }
        
        for(int i=idx;i<nums.size();i++){
            swap(nums[i],nums[idx]);
            solve(idx+1,nums,f_ans);
            // if are not taking nums by refrence we could erase 24 line but taking refrence is space efficient
            swap(nums[i],nums[idx]);
            
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> f_ans;
        solve(0,nums,f_ans);
        
        return f_ans;
        
    }
};