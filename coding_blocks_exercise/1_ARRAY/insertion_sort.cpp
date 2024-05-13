#include<iostream>
using namespace std;

//pehle element ko sorted mante h baki element ko us sorted array m dal dete h

void insertion_sort(int a[], int n){
    for(int i=1;i<=n;i++){

      int e = a[i];
      int j=i-1;
      while(j>=0 and a[j]>e){
          a[j+1]=a[j];
          j=j-1;

      }
      a[j+1]=e;
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


        insertion_sort(a,n);

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        
    }
      }

    

