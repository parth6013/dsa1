// kadanes algorithm

// https://leetcode.com/problems/maximum-subarray/submissions/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int ans=INT_MIN;
        int ans_neg=INT_MIN;
        int csum=0;
        
        for(int i=0;i<nums.size();i++){
            
            ans_neg=max(ans_neg,nums[i]);
            csum=csum+nums[i];
            ans=max(ans,csum);
            if(csum<0){
                csum=0;
            }
            
            
        }
        
        if(ans<=0){
            return ans_neg;
        }else{
            return ans;
        }
        
        
    }
};