#include<iostream>
using namespace std;

//pehele minimum dhunte h phir usko last m bhejdete h

void selection_sort(int a[], int n){

    for(int i=0;i<n-1;i++){
        //finding the minimum in unsorted array
        int min=i;
        for(int j=i;j<n;j++){
            
            if(a[j]<a[min]){
                min=j;
            }
        
              
        }
        //now swapping as it is an expensie operation
        swap(a[i],a[min]);
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


        selection_sort(a,n);

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        
    }
      }

    

