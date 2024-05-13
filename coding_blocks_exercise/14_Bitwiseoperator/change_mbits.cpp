#include<iostream>
using namespace std;

int binaryToDecimal(int n)
{
    int num = n;
    int dec_value = 0;
 
    // Initializing base value to 1, i.e 2^0
    int base = 1;
 
    int temp = num;
    while (temp) {
        int last_digit = temp % 10;
        temp = temp / 10;
 
        dec_value += last_digit * base;
 
        base = base * 2;
    }
 
    return dec_value;
}

int clean1(int n,int i,int j,int m){

    int a= -1<<j+1;
    int b= ~(-1<<i);

    int mask = a | b;


    
    n = n & mask;

    m=m<<i;

    int ans= n|m;

    return ans;


}


int main(){
    int n,m;
    n=15;
    m=2;

     int i,j;
    i=1;
    j=3;

    int ans=clean1(n,i,j,m);

    cout<<ans;

   

}