// 1) BRUTE FORCE WAY iterate over i,j in N^2 and calculate sum in N ways for every N^2 hence N^3 time

// 2)First calculate prefix array then iterate stil N^2 for iteration O(1) for calculation of sum

#include<iostream>
using namespace std;

int maxsum(int arr[],int n){

    int dp[100]={100};

    dp[0]=arr[0]>0 ? arr[0]:0;

    int max_till_now = dp[0];

    for(int j=1;j<n;j++){

        if(dp[j-1]+arr[j]>0){
            dp[j]=dp[j-1]+arr[j];
        }
        else{
            dp[j]=0;
        }
        max_till_now= max(max_till_now,dp[j]);
    }

    return max_till_now;

}



int main(){

    int arr[]={-3,2,5,-1,6,3,-2,7,-5,2};
    int n=10;

    cout<<maxsum(arr,n);



}









