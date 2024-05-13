#include<iostream>
using namespace std;

int main(){

    int m=4;
    int n=5;
    int a[m][n];
    int val=1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            a[i][j]= val;
            val=val+1;
        }
    }

        for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
            
        }
        cout<<endl;
    }

    
    

}


