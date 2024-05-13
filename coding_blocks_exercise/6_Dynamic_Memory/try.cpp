#include<iostream>
using namespace std;

int main(){

    // static
    // allocation and deallocation is done by compiler

    int b[100];
    //will show size of whole array
    cout<<sizeof(b)<<endl;

    // Dynamic allocation
    int n;
    cin>>n;
    // a stores the address of array
    int * a = new int [n];
    // will show size of pointer variable only
    cout<<sizeof(a)<<endl;

    // after allocation there is no change in working

    for(int i=0;i<n;i++){
        cin>> a[i];
        cout<<a[i]<<" ";

    }
    cout<<endl;

    // deallocate memory
    delete [] a;


}