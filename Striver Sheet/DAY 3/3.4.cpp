// elements appearing more than n/3 times


// brute force using map and set
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
   set<int>s;
        
        
        
        map<int,int> m;
        
        vector<int> ans;
        
        if(nums.size()/3==0){
            ans.push_back(nums[0]);
            if(nums.size()==2 && nums[1]!=nums[0]){
                // cout<<nums[1]<<nums[0];
                ans.push_back(nums[1]);
            }
            
            return ans;
        }
        
      
        
        for(int i=0;i<nums.size();i++){
            
            auto it =m.find(nums[i]);
            
            if(it==m.end()){
                m.insert(pair<int,int>(nums[i],1));
           
                
                
            }
            else{
                it->second++;
                if(it->second>nums.size()/3){
                    s.insert(it->first);
                    // ans.push_back(it->first);
                }
            }
            
        }
        
        for(auto it:s){
            ans.push_back(it);
        }
        
        
        return ans;
        
        

        
        
    }
};

// moose voting system updated
// numbers greater than n/3 ,there can be at most 2 such numbers
// so we find two majority numbers then cnt their repetitions and check if > n/3;


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        vector<int> ans;
        
        int n1=INT_MIN;
        int n2=INT_MIN;
        
        int c1=0;
        int c2=0;
        
        
        for(int i=0;i<nums.size();i++){
          if(n1==nums[i]){
              c1++;
          }
            else if(n2==nums[i]){
                c2++;
            }
            else if(c1==0){
                n1=nums[i];
                c1=1;
            }else if(c2==0){
                n2=nums[i];
                c2=1;
            }
            else{
                c1--;
                c2--;
            }
            
            
        }
        
        int cnt=0;
        int cnt2=0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]==n1){
                cnt++;
            }
            if(nums[i]==n2){
                cnt2++;
            }
        }
        
        if(cnt>nums.size()/3){
            ans.push_back(n1);
        }
        
              if(cnt2>nums.size()/3){
            ans.push_back(n2);
        }
        
        return ans;
        
        
    }
};