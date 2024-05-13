#include<iostream>
using namespace std;



void bubble_sort(int a[], int n){
    //heaviest elemt get to end of the array
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
            }
        } 
    }

}

int main(){

    cout<<"Enter the number in array"<<endl;
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        
    }
    cout<<endl;


        bubble_sort(a,n);

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        
    }
      }

    

