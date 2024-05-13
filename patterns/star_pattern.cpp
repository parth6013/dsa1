#include<iostream>
using namespace std;

int main(){

    int n;
    cin>>n;
    // int k=3;
    // int f=1;

//use coordinates to find logic
    for(int i=1;i<=3;i++){
        for(int j=1;j<=n;j++){
            if(((i+j)%4==0) || (i==2 && j%4==0)){
                cout<<"# ";
            }
            else{
                cout<<"  ";
            } 

    }
    cout<<endl;

}
}