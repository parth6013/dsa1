// Reverse Pairs

// https://leetcode.com/problems/reverse-pairs/


// brute force O(n^2);





#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        
        int cnt=0;
        
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                
                if(nums[i]>2*nums[j]){
                    cnt++;
                }
            }
        }
        
        return cnt;
        
    }
};