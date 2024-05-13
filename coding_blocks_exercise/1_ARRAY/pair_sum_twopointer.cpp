//to pick the pair in sorted array having their sum as given

#include<iostream>
using namespace std;

int main(){

    int s;
    cin>>s;

    int n;
    cin>>n;
    
    int a[n];

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int i=0;
    int j=n-1;

    while(i<j){
        cout<<a[i]<<"comparing"<<a[j]<<endl;
        if(a[i]+a[j]>s){
            j=j-1;
        }
        if(a[i]+a[j]<s){
            i=i+1;
        }
        if( a[i]+ a[j]==s){
            cout<<a[i]<<" "<<a[j]<<endl;
            i=i+1;
            j=j-1;
        }
    }

}