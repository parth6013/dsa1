#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;


        int max(int a,int b){
            if(a>b){
                return a;
            }else{
                return b;
            }
        }
    
        
        


int solve1(vector<int> &nums,int n,vector<int> &dp){
    
    if(dp[n]!=-1){
        return dp[n];
    }
    
    if(n==1){
        return dp[n]=nums[0];
    }
    
    if(n==0){
        return dp[n]= 0;
    }
    
    int opt1= nums[n-1] + solve1(nums,n-2,dp);
    int opt2=solve1(nums,n-1,dp);
    
    return dp[n]= max(opt1,opt2);
}

    int solve2(vector<int> nums){

        int n=nums.size();

        vector<int> dp(n+1,0);
        dp[0]=0;
        dp[1]=nums[0];

        for(int i=2;i++;i<nums.size()){

            int opt1=nums[i-1]+dp[i-2];
            int opt2=dp[i-1];

            if(opt1>opt2){
                dp[i]=opt1;
                
            }else{
                dp[i]=opt2;
            }
            cout<<dp[i]<<" ";

        }

        // return dp[n-1];

    }

    int main(){

        int arr[]={3,2,7,10};

        vector<int>  arr2={1, 2, 3 ,5,4};

        // vector<int> dp(4+1,-1);

        // solve(arr,3,dp);

        vector<int> dp(arr2.size()+1,-1);

        // cout<<solve1(arr2,arr2.size(),dp);

        cout<<solve2(arr2);


        // cout<<dp[3];

    }
