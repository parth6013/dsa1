#include<iostream>
using namespace std;

int main(){

    int n;
    cin>>n;
    int n2=n;
    int sum=0;
    
    int r;


    while(n!=0){
        r=n%10;

        sum=sum + (r*r*r);

        n=n/10;
        
        
    }
    cout<<sum<<endl;
    if(n2==sum){
        cout<<n2<<" It's an armstrong number";
    }
    else{
        cout<<n2<<" It's not an armstrong number";
    }
}