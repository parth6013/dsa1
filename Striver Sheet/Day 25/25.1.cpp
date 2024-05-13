// Maximum Product Subarray
#include<bits/stdc++.h>
using namespace std;

// it takes n^3 to produce all possible subarray 

// but to just canculate prod it takes n^2 but gives tle
class Solution {
public:
    
    void solve(){
        
    } 
    int maxProduct(vector<int>& nums) {
        
        int s_ans;
        int ans=INT_MIN;
        
        int n=nums.size();
        for(int i=0;i<n;i++){
            s_ans=1;
            for(int j=i;j<n;j++){
                s_ans=s_ans*nums[j];
                // cout<<s_ans<<endl;
                ans=max(ans,s_ans);
            }
        }
        
        
        return ans;
        
    }
};


// if there was no negative we can use kadane like formula but here its negative and as soon as negative meets another it becomes +ve and lowest become highest
// so we maintin both highest and lowest
int maxProduct(vector<int>& nums) {
    if(nums.empty()) {
        return 0;
    }
    int currentMax = nums[0];
    int currentMin = nums[0];
    int maxProduct = nums[0];
    
    for(size_t i = 1; i < nums.size(); ++i) {
        //calculate our new possibilities for this round
        int p1 = currentMax * nums[i];
        int p2 = currentMin * nums[i];
        //our currentMax will be either p1 or p2 or nums[i] whichever is bigger
        currentMax = max(nums[i], max(p1, p2));
        //our currentMin will be either p1 or p2 or nums[i] whichever is smaller
        currentMin = min(nums[i], min(p1, p2));
        //our maxProduct will be our currentMax or our maxProduct, whichever is bigger.
        maxProduct = currentMax > maxProduct ? currentMax : maxProduct;
    }
    return maxProduct;
}


class Solution {
public:
    
    //we are using kaden's algo logic
    //we are here using two pass method so that we can get ultimate max
    
    int maxProduct(vector<int>& nums) {
        
        int prod=1;
        int max_val=INT_MIN;
        
        //left to right traversal
        for(int i=0;i<nums.size();i++)
        {
            if(prod==0)//if prod becomes 0, prod is reset to 1
                prod=1;
            
            prod=prod*nums[i];
            max_val=max(max_val,prod); 
        }
        
        //right to left
        prod=1;
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(prod==0)
                prod=1;
            
            prod=prod*nums[i];
            max_val=max(max_val,prod);
        }
        
        return max_val;
        
    }
};