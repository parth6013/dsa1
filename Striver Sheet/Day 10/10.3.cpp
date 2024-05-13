// Sudoku

// Pure brute force but tle
#include<bits/stdc++.h>
using namespace std;



// striver
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    
    bool solve(vector<vector<char>>& board){
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == '.'){
                    for(char c = '1'; c <= '9'; c++){
                        if(isValid(board, i, j, c)){
                            board[i][j] = c; 
                            // suppose we have filled a number in a manner that no another number can accomodate we get false
                            // and we use another number instead and go forward
                            if(solve(board))
                                return true; 
                            else
                                board[i][j] = '.'; 
                        }
                    }
                    
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isValid(vector<vector<char>>& board, int row, int col, char c){
        for(int i = 0; i < 9; i++) {
            if(board[i][col] == c) 
                return false; 
            
            if(board[row][i] == c) 
                return false; 
            
//             by 3*row/3 and 3* col/3 we select which box in 9 box then with i we iterate
            if(board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) 
                return false; 
        }
        return true;
    }
};







// pure brute


class Solution {
public:
    
    void solve(int ind1,int ind2,vector<vector<char>>& board){
        
//  conditions for checking if all are filled       
        if(ind1==9 && ind2==9){
            // cout<<"okay";
            map<int,int> mpp;
            map<int,int> mpp2;
            map<int,int> mpp3;
            
            for(int m1=0;m1<9;m1++){
                for(int m2=0;m2<9;m2++){
                    if(mpp.find(board[m1][m2])==mpp.end()){
                        mpp[board[m1][m2]]++;
                    }else{
//                         same number in row
                        return;
                    }
                }
                mpp.clear();
            }
            
                        for(int m1=0;m1<=9;m1++){
                for(int m2=0;m2<=9;m2++){
                    if(mpp2.find(board[m2][m1])==mpp2.end()){
                        mpp2[board[m2][m1]]++;
                    }else{
//                         same number in column
                        return;
                    }
                }
                            mpp2.clear();
                            
            }
            
    for(int k1=0;k1<=6;k1=k1+3){
        for(int k2=0;k2<=6;k2=k2+3){
//             selecting 3*3 box ,now traversing in 3*3 box
            for(int l1=k1;l1<k1+3;l1++){
                for(int l2=k2;l2<k2+3;l2++){
                    if(mpp3.find(board[l1][l2])==mpp3.end()){
                        mpp3[board[l1][l2]]++;
                    }else{
//                         same in 3*3 box 
                        return;
                    }
                }
            }
//             clear after 3*3 loop
            mpp3.clear();
        }
    }
            cout<<"yes";
            return;
            
        }
        
// To enter values
        for(int i=ind1;i<9;i++){
            for(int j=ind2;j<9;j++){
                if(board[i][j]=='.'){
                    for(int k=1;k<=9;k++){
                        board[i][j]=static_cast<char>(i);
                        solve(i,j,board);
                        board[i][j]='.';
                    }
                }
            }
        }
        
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<char>> ans;
        solve(0,0,board);
    }
};