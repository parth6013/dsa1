// combination sum 1
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<int> &candidates,int ind,int target,vector<int> &sub_ans,vector<vector<int>>& f_ans){
        
        if(ind==candidates.size()){
            if(target==0){
                cout<<"yes";
                f_ans.push_back(sub_ans);
            }
            return;
        }
        
//         pick
        if(candidates[ind]<=target){
            sub_ans.push_back(candidates[ind]);
            solve(candidates,ind,target-candidates[ind],sub_ans,f_ans);
            sub_ans.pop_back();
        }
        
//         not pick
        solve(candidates,ind+1,target,sub_ans,f_ans);
        
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> f_ans;
        vector<int> sub_ans;
        solve(candidates,0,target,sub_ans,f_ans);
        
        return f_ans;
    }
};