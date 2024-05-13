#include<iostream>
using namespace std;

void yolo(char*out,int n,int index,int open1,int close1){
// we equate to 2n cause after 2n-1 is index is filled then we want to do 
if(index==2*n){
    out[index]='\0';
    cout<<out<<endl;
    return;
}

if(open1<n){
    out[index]='(';
    yolo(out,n,index+1,open1+1,close1);
}
if(close1<open1){
    out[index]=')';
    yolo(out,n,index+1,open1,close1+1);
}

}


int main(){

char out[1000];

yolo(out,2,0,0,0);


}