#include<bits/stdc++.h>
#include<math.h>
using namespace std;

// int dec(int n){

//     int sum=0;
//     int b=0;
//     int r;

//     while(n>0){
//         r=n%10;
//         sum= sum +pow(r,b);
//         b=b+1;

//         n=n/10;
        


//     }

//     return sum;

// }


int main(){

    int n;
    cin>>n;
        int sum=0;
    int b=1;
    int r;

    while(n>0){
        r=n%10;
        cout<<b*r<<endl;
        sum= sum + b*r;
        b=b*2;

        n=n/10;
        


    }
    // cout<<dec(n);
    cout<<sum;

}