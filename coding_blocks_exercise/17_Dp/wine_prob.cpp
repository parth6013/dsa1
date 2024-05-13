// you could sell bottles present at extream of array and price get increase as year
// greedy aprroach is worng that bottle whic is less in extreme sell that because it also affects the price of bottle next to them
// SO now
#include<iostream>
using namespace std;
// top down approach
int maxprofit(int arr[],int i ,int j,int y,int dp[][100]){

    // base
    if(i>j){
        return 0;
    }

    if(dp[i][j]!=0){
        return dp[i][j];
    }
    
    // recursive
    int op1= arr[i]*y + maxprofit(arr,i+1,j,y+1,dp);
    int op2=arr[j]*y + maxprofit(arr,i,j-1,y+1,dp);
    
    return dp[i][j] = max(op1,op2);



}


int main(){

    int arr[]={2,3,5,1,4};
    int i=0;
    int j=4;
    int dp[100][100]={0};
    cout<<maxprofit(arr,i,j,1,dp);



}

