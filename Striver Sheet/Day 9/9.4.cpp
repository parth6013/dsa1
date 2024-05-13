// combination sum_2

// brute is using  same as combination sum 1 and set

// optimised
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void solve(int idx,int target,vector<int>&s_ans,vector<vector<int>> &f_ans,vector<int> &candidates){
        
        
            if(target==0){
                cout<<"yes";
                f_ans.push_back(s_ans);
                return;
            }
            
       
        
        for(int i=idx;i<candidates.size();i++){
            if(i!=idx && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]<=target){
                s_ans.push_back(candidates[i]);
                solve(i+1,target-candidates[i],s_ans,f_ans,candidates);
                s_ans.pop_back();
            }
            
            
            
        }
        
        
        
    }
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> s_ans;
        vector<vector<int>> f_ans;
        sort(candidates.begin(),candidates.end());
        solve(0,target,s_ans,f_ans,candidates);
        
        return f_ans;
        
    }
};