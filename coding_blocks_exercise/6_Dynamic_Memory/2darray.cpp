// No direct way to create 2d dynamic array; n static consecutive adress is give in heap its random
#include<iostream>
using namespace std;

int main(){

int ** arr; // to store array of locations

int r,c;
cin>>r>>c;

arr=new int*[r];//intializing it

// crate 2d array
for(int i=0;i<r;i++){

    arr[i] = new int[c]; //holding adress of array c

}
// now normal functions
int val=1;
for(int i=0;i<r;i++){
    for(int j =0;j<c;j++){
        arr[i][j] = val;
        val++;
        cout<<arr[i][j];
    }
    cout<<endl;
}
}