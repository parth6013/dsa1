// Q Queens
#include<bits/stdc++.h>
using namespace std;


// optimum soln ek row m ek hi ho skta and moving in diagonals efficient

class Solution {
public:
    vector<vector<string>> ret;
    bool is_valid(vector<string> &board, int row, int col){
        // check col
        for(int i=row;i>=0;--i)
            if(board[i][col] == 'Q') return false;
        // check left diagonal
        for(int i=row,j=col;i>=0&&j>=0;--i,--j)
            if(board[i][j] == 'Q') return false;
        //check right diagonal
        for(int i=row,j=col;i>=0&&j<board.size();--i,++j)
            if(board[i][j] == 'Q') return false;
        return true;
    }
    void dfs(vector<string> &board, int row){
        // exit condition
        if(row == board.size()){
            ret.push_back(board);
            return;
        }
        // iterate every possible position
        for(int i=0;i<board.size();++i){
            if(is_valid(board,row,i)){
                // make decision
                board[row][i] = 'Q';
                // next iteration
                dfs(board,row+1);
                // back-tracking
                board[row][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
		// return empty if n <= 0
        if(n <= 0) return {{}};
        vector<string> board(n,string(n,'.'));
        dfs(board,0);
        return ret;
    }
};



// my soln
class Solution {
public:
    
   void solve(vector<string>&s1,int row,vector<vector<string>> &ans){
       int n=s1.size(); 
       
        if(row==n){
            ans.push_back(s1);
            return;
        }
        
        
            for(int j=0;j<n;j++){
                if(s1[row][j]=='.'){
                    if(okay(s1,row,j)){
                        s1[row][j]='Q';
                        solve(s1,row+1,ans);
                        s1[row][j]='.';
                        
                    }
                }
            }
        
        
    }
    
    bool okay(vector<string> s1,int i,int j){
        int n=s1.size();
        
        for(int k=0;k<n;k++){
            if(s1[i][k]=='Q' && k!=j){
                return false;
            }
            if(s1[k][j]=='Q'&& k!=i){
                return false;
            }
        }
        
        // for(int m1=i,m2=j;i>=0&&j>=0;--m1,--m2)
        //     if(s1[m1][m2] == 'Q') return false;
        
        int m1=i;
        int m2=j;
//         left upper diagonal
        while(m1>=0 && m2>=0){
            if(s1[m1][m2]=='Q' && m1!=i && m2!=j){
                return false;
            }
            m1--;
            m2--;
        }
//         right upper
        m1=i;
        m2=j;
        
          while(m1>=0 && m2<n){
            if(s1[m1][m2]=='Q' && m1!=i && m2!=j){
                return false;
            }
            m1--;
            m2++;
        }
//         right lower
        m1=i;
        m2=j;
        while(m1<n && m2<n){
            if(s1[m1][m2]=='Q' && m1!=i && m2!=j){
                return false;
            }
            m1++;
            m2++;
        }
        
//         left lower
        m1=i;
        m2=j;
        while(m1<n && m2>=0){
            if(s1[m1][m2]=='Q' && m1!=i && m2!=j){
                return false;
            }
            m1++;
            m2--;
        }
        // cout<<"okay";
        
        return true;
        
    }
    
    
    
    vector<vector<string>> solveNQueens(int n) {
        string s="";
        for(int i=0;i<n;i++){
            s=s+".";
        }
        vector<string> s1;
        for(int i=0;i<n;i++){
            s1.push_back(s);
        }
        
        vector<vector<string>> ans;
        solve(s1,0,ans);
        return ans;
        
    }
};