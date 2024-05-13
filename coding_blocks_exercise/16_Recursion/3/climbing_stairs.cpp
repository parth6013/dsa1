#include<iostream>
using namespace std;


// int tot(int n){

//     if(n==0){
//         return 0;
//     }
//     if(n==1){
//         return 1;
//     }
//     if(n==2){
//         return 2;
//     }
//     if(n==3){
//         return 4;
//     }
//     if(n==4){
//         return 7;
//     } 

//     if(n>4){
//         int q=n/4;
//         int r=n%4;

//         return q* tot(4) + tot(r);
//     }




// }

int tot2(int n,int k){

    if(n==0){
        return 1; 
    }

    if(n<0){
        return 0;
    }

    int ans=0;
    // if k=3
    // return tot2(n-1) + tot2(n-2) +tot2(n-3); 

    // but if k is variable

    for(int i=0;i<=k;i++){
        ans = ans+ tot2(n-i,k);
    }
    return ans;

}


int main(){

    int m = tot2(4,3);
    cout<<m;

}