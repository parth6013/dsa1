#include<iostream>
#include<bits.h>
#include<string.h>

using namespace std;

int num(char* a,int n){
    if(n==0){
        return 0;
    }

    int digit = a[n-1] - '0';
    int small_ans=num(a,n-1);

    return small_ans*10 + digit;


}


int main(){
    
    char a[] ={"1234"};

    int n= strlen(a);

    int m=num(a,n);

    cout<<m;


    return 0;
}