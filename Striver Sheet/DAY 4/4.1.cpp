// two sum

// https://leetcode.com/problems/two-sum/

// brute force n^2

//2) nlgn for sort then select n *logn(binary search)

// take first element and seach for target- elemet in map if we found it then okay else push that element in mapp
// if we are using unorderd map best case O(n) worst case O(n^2)

// here we are storing index as value in map

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> ans;
        unordered_map<int,int> mpp;
        
        for(int i=0;i<nums.size();i++){
            
            if(mpp.find(target-nums[i])!=mpp.end()){
                
                ans.push_back(mpp[target-nums[i]]);
                ans.push_back(i);
                return ans;
                
            }else{
                mpp[nums[i]]=i;
            }
            
            
        }
        return ans;
        
        
        
    }
};