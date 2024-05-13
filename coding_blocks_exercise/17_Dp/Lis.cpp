#include<iostream>
#include<climits>
using namespace std;

int lis_brute(int arr[],int n){

    int dp[n];

    for(int i=0;i<n;i++){
        // each element can have at least its own substring
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i]){
               dp[i]= max(dp[i],dp[j]+1);
            }
        }
    }

    int lis=0;
    for(int i=0;i<n;i++){
        cout<<dp[i]<<" ";
        lis=max(lis,dp[i]);
    }

    cout<<endl;
    return lis;

}
//  a little tricky method  still N^2
int lis_brute2(int arr[],int n){

    int dp[n+1];

    dp[0]=INT_MIN;
    for(int i=1;i<=n;i++){
        dp[i]=INT_MAX;
    }



   for(int i=0;i<n;i++){
       for(int length=0;length<n;length++){
           if(dp[length]<arr[i] && arr[i]<dp[length+1]){
                dp[length+1]=arr[i];
           }
       }
   }

    int lis=0;
    for(int i=1;i<=n;i++){
        cout<<dp[i]<<" ";
        if(dp[i]!=INT_MAX){
            lis=i;
        }
    }

    cout<<endl;
    return lis;

}



int main(){

    int arr[]={1,5,2,3,4,9,6,10};

    int  n=sizeof(arr)/sizeof(arr[0]);

    cout<<lis_brute2(arr,n);

    





}