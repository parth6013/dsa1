#include<iostream>
#include<climits>
using namespace std;

// // Brute ans
// int min1(int n){
// // Base case
//     if(n==1){
//         return 0;
//     }

//     int ans;

//     if(n%3==0){
//         n=n/3;
//         ans= 1+ min1(n);
//         return ans;
//     }

//     if(n%2==0){
//         n=n/2;
//         ans= 1 + min1(n);
//         return ans;
//     }

//     n=n-1;
//     ans=1+ min1(n);
//     return ans;





// }


// top down recursive approach
int minsteps(int n ,int dp[]){

    if(n==1){
        return 0;
    }

    if(dp[n]!=0){
        return dp[n];
    }

    int op1=INT_MAX;
    int op2=INT_MAX;
    int op3=INT_MAX;


    if(n%3==0){
        op1=minsteps(n/3,dp) ;
    }

    if(n%2==0){
        op2=minsteps(n/2,dp) ;
    }

    op3=minsteps(n-1,dp) ;

    int ans=min(min(op1,op2),op3) +1;

    return dp[n]=ans;
}

// bottom up approach


int min3(int n){

  int dp[100]={0};

    dp[1]=0;

    int op1,op2,op3;

    

    for(int i=2;i<=n;i++){

        op1=op2=op3=INT_MAX;

        if(n%3==0){
            op1=dp[i/3]+1;
        }
        if(n%2==0){
            op2=dp[i/2]+1;

        }
        op3=dp[i-1] +1;

        dp[i]=min(min(op1,op2),op3) ;
        

    }

    return dp[n];

}

int main(){

    int dp[100]={0};
    cout<<minsteps(10,dp);

    cout<<min3(10);


}