// making rows and column 0 of that element which is 0

// https://leetcode.com/problems/set-matrix-zeroes/submissions/

// Brute Force approach - traverse the matrix then mark rows and column no which has 0 
// traverse them now and make it zero N^2 + N^2 + N^2

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int m= matrix.size();
        int n=matrix[0].size();
        
        cout<<m<<n;
        
        vector<vector<int>> check(m, vector<int> (n, 0));
        
        vector<int> row(m,0);
        vector<int> column(n,0);
        
        
        
        
//         marking elements which is 0
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    check[i][j]=1;
                    row[i]=1;
                    column[j]=1;
                }
            }
        }
        
//   making row 0
        
        for(int i=0;i<m;i++){
            if(row[i]==1){
                for(int j=0;j<n;j++){
                    matrix[i][j]=0;
                }
            }
        }
        
//    making column 0
        
        for(int i=0;i<n;i++){
            if (column[i]==1){
                for(int j=0;j<m;j++){
                    matrix[j][i]=0;
                }
            }
        }
        
        
        
        
    }
};


// approach 2 optimise we make first row and column as dummy row and column and traverse in the m-1 and n-1 snad mark them
// only game is for 0,0 element as it is responsible for forst row and column as well so we make it a variable to see also
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
    bool isCol = false;
    int R = matrix.size();
    int C = matrix[0].size();

    for (int i = 0; i < R; i++) {

      // Since first cell for both first row and first column is the same i.e. matrix[0][0]
      // We can use an additional variable for either the first row/column.
      // For this solution we are using an additional variable for the first column
      // and using matrix[0][0] for the first row.
      if (matrix[i][0] == 0) {
        isCol = true;
      }

      for (int j = 1; j < C; j++) {
        // If an element is zero, we set the first element of the corresponding row and column to 0
        if (matrix[i][j] == 0) {
          matrix[0][j] = 0;
          matrix[i][0] = 0;
        }
      }
    }

    // Iterate over the array once again and using the first row and first column, update the elements.
    for (int i = 1; i < R; i++) {
      for (int j = 1; j < C; j++) {
        if (matrix[i][0] == 0 || matrix[0][j] == 0) {
          matrix[i][j] = 0;
        }
      }
    }

    // See if the first row needs to be set to zero as well
    if (matrix[0][0] == 0) {
      for (int j = 0; j < C; j++) {
        matrix[0][j] = 0;
      }
    }

    // See if the first column needs to be set to zero as well
    if (isCol) {
      for (int i = 0; i < R; i++) {
        matrix[i][0] = 0;
      }
    }
  }
};