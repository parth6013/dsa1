 #include<iostream>
 using namespace std;


 void floodFill(char mat[][50],int i,int j,char ch,char color){

     static int R=10,C=10;

     static int dx[]={-1,0,1,0};
     static int dy[]={0,-1,0,1};


    //  Base Case - Matrix Bounds
    if(i<0 || j<0 || i>=R || j>=C){
        return;
    }

    // Figure Boundary Condition
    if(mat[i][j]!=ch){
        return;
    }

    // Recursive call
    mat[i][j]=color;
    for(int k=0;k<4;k++){
        floodFill(mat,i+dx[k],j+dy[k],ch,color);
    }

 }