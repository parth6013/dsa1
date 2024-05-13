#include<iostream>
using namespace std;
//sorted  array lete h  agar key element mid point bada h toh second half m dhundho
int main(){

    cout<<"Enter the number in array"<<endl;
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cout<<a[i];
        
    }
    cout<<endl;

    int s=0;
    int e=n-1;

    int key;
    cout<<"Enter number you want to seacrh"<<endl;
    cin>>key;
    int f=0;
    while(s<=e){
        int m=(s+e)/2;
        if(a[m]==key){
            cout<<m<<"Its the postion of key"<<endl;
            f=1;
            break;
        }

        if(key>a[m]){
            s=m+1;
        }
        if(key<a[m]){
            e=m-1;
        }        
    }

    if(f==0){
        cout<<"Not Present in array";
    }

}