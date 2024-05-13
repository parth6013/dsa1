#include<iostream>
using namespace std;

bool compare(int a,int b){
    // 5cout<<"comparing "<<a<<"and "<<b;
    return a < b ;
}

void bubble_sort(int a[], int n,bool (&cmp)(int a,int b)){
    //heaviest elemt get to end of the array
    for(int i=0;i<n-1;i++){
        for(int j=0;j<=n-i-1;j++){
            if(cmp(a[j],a[j+1])){
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


        bubble_sort(a,n,compare);

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        
    }
      }

    

