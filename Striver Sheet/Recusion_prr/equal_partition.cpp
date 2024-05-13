// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

// recusion ans
class Solution{
public:

    void solve(int i,int N,int arr[],int s1,int s2,bool &ans){
        
        if(ans==true){
            return;
        }
        
        if(i==N){
            if(s1==s2){
                ans=true;
            }
            return;
        }
        
        // put in s1 not in s2
        solve(i+1,N,arr,s1+arr[i],s2,ans);
        
        //in s2 not in s1
        solve(i+1,N,arr,s1,s2+arr[i],ans);
        
        
    }
    
    
    
    int equalPartition(int N, int arr[])
    {
        // code here
        
        bool ans=false;
        int s2=0;
        int s1=0;
        
        solve(0,N,arr,s1,s2,ans);
        
        return ans;
        
        
        
        
        
    }
};


// Now if given array sum is odd by no means we can divide into two subset as they arre odd
// if its even there is a chance so we give sum/2 to fn to find if this subset sum exist if yes then remaining one is equal to it

 
class Solution{
public:

    void solve(int i,int N,int arr[],int s1,int s2,bool &ans){
        
        if(ans==true){
            return;
        }
        
        if(i==N){
            if(s1==s2){
                ans=true;
            }
            return;
        }
        
        // put in s1 not in s2
        solve(i+1,N,arr,s1+arr[i],s2,ans);
        
        //in s2 not in s1
        solve(i+1,N,arr,s1,s2+arr[i],ans);
        
        
    }
    
    
    
   int solve_memo(int N,int arr[],int sum1,vector<vector<int>>& dp){
        
        if(dp[N][sum1]!=-1){
            return dp[N][sum1];
        }
        
        if(sum1==0){
            return 1;
        }
        
        if(N<=0){
            return 0;
        }
        
        if(arr[N-1]>sum1){
           return dp[N-1][sum1]= solve_memo(N-1,arr,sum1,dp);
        }else{
            
            return dp[N-1][sum1]=(solve_memo(N-1,arr,sum1,dp)||solve_memo(N-1,arr,sum1-arr[N-1],dp));
            
        }
        
    }
    
    int solve_bottom_up(int N,int arr[],int sum1){
        
        
        
 vector<vector<int>> dp(N+1,vector<int>(sum1+1,0));



for (int i = 0; i <= N; i++)

dp[i][0] = 1;
        
 
        
        for(int i=1;i<=N;i++){
            for(int j=1;j<=sum1;j++){
                
                if(j<arr[i-1]){
                    dp[i][j]=dp[i-1][j];
                }else{
                    // cout<<"x";
                    dp[i][j]=(dp[i-1][j]||dp[i-1][j-arr[i-1]]);
                }
                
            }
        }
        
        
        return dp[N][sum1];
        
        
        
        
    }
    
  
    
    
    int equalPartition(int N, int arr[])
    {
        // code here
        
        bool ans=false;
        int s2=0;
        int s1=0;
        
        // solve(0,N,arr,s1,s2,ans);
        
        // return ans;
        
        
        
        int sum1=0;
        
        for(int i=0;i<N;i++){
            sum1+=arr[i];
        }
        
        // cout<<sum1<<endl;
        
        if((sum1)%2==0){
            
            // vector<vector<int>> dp(N+1,vector<int>(sum1+1,-1));
        
        // return solve_memo(N,arr,(sum1)/2,dp);
        
            // return solve_bottom_up(N,arr,(sum1)/2); 
            
            // int ans= solve3(arr,N,(sum1)/2);
            
            int ans= solve_bottom_up(N,arr,(sum1)/2);
            
            return ans;
            
        }else{
            
            // cout<<"x";
            
            return 0;
        }
        
        
        
        
        
    }
};