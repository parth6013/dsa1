#include<iostream>
#include<algorithm>

using namespace std;

// making a comparator, if you make a>b it will reverse the order
bool compare(int a,int b){
    
    return a < b;

}
int main(){

    int a[1000];
    int n;

    cin>>n;

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
// passing a function as a parameter
    sort(a,a+n,compare);

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}