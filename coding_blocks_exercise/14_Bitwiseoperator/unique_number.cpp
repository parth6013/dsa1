// in this problem an array is given each element has frequency 2 ,except 1 find that number
#include<iostream>
using namespace std;

int main(){

    int n;

    cin>>n;
    
    int ans =0;
    
    
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        ans=ans^x;
    }

    cout<<ans<<endl;

    return 0;

}