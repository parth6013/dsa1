#include<iostream>
#include<vector>
using namespace std;
// brute approach for 3 max steps;
void ladder_ways(int target,int a[],int i){

    if(target==0){
        int z=0;
        while(a[z]!=0){
            cout<<a[z]<<" ";
            z++;
        }
        cout<<endl;


        return;
    }

    if(target<0){
        return;
    }

    // 1

    a[i]=1;
    ladder_ways(target-1,a,i+1);
    


    // 2
     a[i]=2;
    ladder_ways(target-2,a,i+1);
    

    // 3
     a[i]=3;
    ladder_ways(target-3,a,i+1);

    a[i]=0;

    // for(int k=1;k<=3;k++){
    //     a[i]
    // }



}
// brute approach for k max jump
void ladder_ways2(int target,int a[],int k,int i){

    if(target==0){
        int z=0;
        while(a[z]!=0){
            cout<<a[z]<<" ";
            z++;
        }
        cout<<endl;


        return;
    }

    if(target<0){
        return;
    }

    for(int j=1;j<=k;j++){
        a[i]=j;
        ladder_ways2(target-j,a,k,i+1);
        a[i]=0;
    }

    

}

// now we dont have to print whole array just no of ways

int ladder_top_down(int n,int k,int dp[]){

    // base case
    if(n==0){
        return 1;
    }

    if(dp[n]!=0){
        return dp[n];
    }

    int ways=0;

    

    for(int i=1;i<=k;i++){
        if(n-i>=0){
            ways += ladder_top_down(n-i,k,dp);
        }
    }

    return dp[n]=ways;

}

// bottum approach adding previous k from dp array

int ladders_bottomup(int n,int k){

    int dp[100]={0};
    // start case
    dp[0]=1;

    for(int i=1;i<=n;i++){
        dp[i]=0;
        for(int j=1;j<=k;k++){
            if(i-j>=0){
                dp[i]+=dp[i-j];
            }
        }
    } 
    // see the bottom up
    for(int i=0;i<=n;i++){
        cout<<dp[i]<<" ";
    }

    return dp[n];
}



int main(){
vector<int> a(100,-1);

int b[100]={0};

// ladder_ways(4,b,0);

// ladder_ways2(4,b,3,0);
cout<<ladder_top_down(4,3,b);




}