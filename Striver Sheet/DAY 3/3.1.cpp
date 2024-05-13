// find an element in sorted matrix

// brute force n^2

// cause it's sorted hence O(n);

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size();
        int n=matrix[0].size();
        // cout<<n<<"#"<<endl;
        int row;
        int f=0;
        int f2=0;
        int column;
        
//         search for row in which target exist
        
        for(int i=0;i<m;i++){
            
            if(target<= matrix[i][n-1]){
                // cout<<i;
                row=i;
                f2=1;
                break;
            }
            
        }
        if(f2==0){
            return false;
        }
        // cout<<matrix[1][0];
// search in which column
        for(int j=0;j<n;j++){
            if(target==matrix[row][j]){
                f=1;
                // cout<<j;
                // column=j;
                break;
                
            }
        }
        
        // cout<<matrix[row][column];
        
        if(f==0){
            return false;
        }
        
        return true;
        
    }
};

// gfg question is little different  if rows are sorted and columns are sorted hence using staircase



class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m=matrix.size();
        int n=matrix[0].size();
        
        int i=0;
        int j=n-1;
        
        if(target<matrix[0][0] || target>matrix[m-1][n-1]){
            return false;
        }
        
        while(i<=m-1 && j>=0){
            cout<<"x"<<endl;
            
            if(target==matrix[i][j]){
                return true;
            }
            
            if(matrix[i][j]>target){
                j--;
                
            }else{
                i++;

            
        }
        
        
        
        
        
    }
    return false;
    }
};

// when its sorted both ways binary search over matrix m*n which is array from 0.... m*n-1

class Solution {
public:
    
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
    // treat the matrix as an array, just taking care of indices
    // [0..n*m]
    // (row, col) -> row*n + col
    // i -> [i/n][i%n]
    if(matrix.empty() || matrix[0].empty())
    {
        return false;
    }
    int m = matrix.size(), n = matrix[0].size();
    int start = 0, end = m*n - 1;
    while(start <= end)
    {
        int mid = start + (end - start)/2;
        int e = matrix[mid/n][mid%n];
        if(target < e)
        {
            end = mid - 1;
        }
        else if(target > e)
        {
            start = mid + 1;
        }
        else
        {
            return true;
        }
    }
    return false;
}
    
};