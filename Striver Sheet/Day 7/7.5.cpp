// max consecutive ones



#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int ans=0;
        int c_ans=0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                c_ans++;
            }else{
                ans=max(ans,c_ans);
                c_ans=0;
            }
        }
        
        ans=max(ans,c_ans);
        
        return ans;
        
        
    }
};
