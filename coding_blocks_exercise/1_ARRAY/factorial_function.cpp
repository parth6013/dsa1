#include<iostream>
using namespace std;

int fib(int n){
    int p =1;
    for(int i=n;i>=1;i--){
        p=p*i;
    }

    return p;
}

int main(){

    int n;
    cin>>n;

    int k=fib(n);

    cout<<k;

}