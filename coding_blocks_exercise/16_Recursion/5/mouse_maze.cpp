#include<iostream>
using namespace std;

bool ratInMaze(char maze[10][10],int soln[][10],int i,int j,int m,int n){

if(i==m && j==n){
    soln[m][n]=1;

    // print the path
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            cout<<soln[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    return true;
}

// rat should be inside grid
if(i>m || j>n){
    return false;
}

if(maze[i][j]=='x'){
    return false;
}

// Assume solution exists through current cell
soln[i][j] = 1;
bool rightSucess=ratInMaze(maze,soln,i,j+1,m,n);
bool downSucess=ratInMaze(maze,soln,i+1,j,m,n);

// Backtracking
soln[i][j] = 0;

if(rightSucess || downSucess){
    return true;
}
return false;

}

int main(){


    
}