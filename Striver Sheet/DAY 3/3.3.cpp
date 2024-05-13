// element appearing greater tha n/2 times
// https://leetcode.com/problems/majority-element/

// brute force use map

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        
        
        map<int,int> m;
        
        int ans;
        
        
        if(nums.size()==1){
            return  nums[0];
        }
        
        for(int i=0;i<nums.size();i++){
            
            auto it =m.find(nums[i]);
            
            if(it==m.end()){
                m.insert(pair<int,int>(nums[i],1));
            }
            else{
                it->second++;
                if(it->second>nums.size()/2){
                    ans=it->first;
                    break;
                }
            }
            
        }
        
        return ans;
        
        
    }
};

// moose voting algorithm

// idea is if majority element is +1 and all minority is -1 then sum has to be atleast 1 or greater than that
// if element is same as previous +1 else -1
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int cnt=0;
        
      int  n1=nums[0];
        
        
        for(int i=0;i<nums.size();i++){
            
            if(nums[i]==n1){
                cnt++;
            }else{
                cnt--;
            }
            if(cnt==0){
                n1=nums[i];
                cnt=1;
            }
            // cout<<nums[i]<<cnt<<n1<<endl;
            
        }
        
        return n1;
        
        
        
    }
};