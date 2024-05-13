// best day to buy and sell stock



#include<bits/stdc++.h>
using namespace  std;

// brute force 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        int min1=prices[0];
        int ans=INT_MIN;
        
     for(int i=0;i<n-1;i++){
         for(int j=i+1;j<n;j++){
             ans=max(ans,prices[j]-prices[i]);
         }
     }
        
        if(ans<0){
            return 0;
        }
        return ans;
    }
};


// you maintain a minimum while you traversing and calculate profit uptill now return max profit;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();

        int profit=0;
        int min1=INT_MAX;
        
        for(int i=0;i<n;i++){
        min1=min(min1,prices[i]);
            profit=max(profit,prices[i]-min1);
        }
        
        return profit;
        
        
    }
};