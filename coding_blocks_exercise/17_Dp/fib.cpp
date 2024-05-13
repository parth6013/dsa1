#include<iostream>
using namespace std;
// for a recursive fibonacii soln space complexity of a stack O(n) at max which is depth of recursion tree
// time comlexity is 1+ 2+ 4+ 8 + 2^n-1= O(2^n)


// regular recursion

int fib1(int n){
    if(n==0){
        return 0;

    }
    if(n==1){
        return 1;

    }

    return fib1(n-1) + fib1(n-2);
}

// top down approach recursion + memorization
// time complexity is maximum depth now which is O(n)
int fib2(int n,int dp[]){
    if(n==0 || n==1){
        return n;
    }


    if(dp[n]!=0){
        
        return dp[n];
    }

    int ans = fib2(n-1,dp) + fib2(n-2,dp);

    dp[n]=ans;

    return dp[n]=ans;



}

// bottom up approach (smaller solution gives answer to bigger solutions)
int fib3(int n){

    int dp[100]={0};
    dp[1]=1;

    if(n!=0 || n!=1){
    for(int i=2;i<=n;i++){

        dp[i]= dp[i-1] + dp[i-2];
    }
    }
    return dp[n];


}
// bottom uproach space optimization;
int fib4(int n){

    if(n==1 || n==0){
        return n;
    }

    int a=0;
    int b=1;
    int c;
    for(int i=2;i<=n;i++){
        c=a+b;
        a=b;
        b=c;

    }
    return c;



}


int main(){

    int dp[100000]={0};
    // cout<<fib1(15)<<endl;
    // cout<<fib2(25,dp);

    // cout<<fib3(5);
   
    cout<<fib4(50);

}