// Unique paths
// https://leetcode.com/problems/unique-paths/

// Brute force is recursion 2^mn but gives tle

// now dp solution which is 0(m*n) using memoization

#include<bits/stdc++.h>
using namespace std;
   
        

class Solution {
public:
    int solve(int i,int j,int m,int n,vector<vector<int>> &dp)
    {
        if(i>=m||j>=n)
            return 0;
        if(i==m-1&&j==n-1)
            return 1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        return dp[i][j]=solve(i+1,j,m,n,dp)+solve(i,j+1,m,n,dp);
    }
    int uniquePaths(int m, int n) {
      vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(0,0,m,n,dp);
    }
};


// for example for 3*2 martrix one could go 
// R R D
// D R R
// R D R 
// so if we decide to put right moves(column) there is only one way for down
// or if we could decide down moves(column) there is only one total way to fill right
// total no of ways is m-1 + n-1 = m+n-2
// so our solution is m+n-2 c m-1 or m+n-2 c n-1

// short for calculating ncr

class Solution {
public:
    int uniquePaths(int m, int n) {
        
        int N = n+m-2;
        int r=m-1;
        double ans=1;
        
        for(int i=1;i<=r;i++){
            ans=ans*(N-r+i)/i;
        }
        
        return int(ans);
        
        
    }
};