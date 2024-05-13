// minimum number of coins needed to reach target
#include<iostream>
#include<climits>
using namespace std;
// top down approach
int mincoins(int n,int coins[],int t,int dp[]){

	if(n==0){
		return 0;
	}

	if(dp[n]!=0){
		return dp[n];
	}

	int ans=INT_MAX;

	for(int i=0;i<t;i++){
		if(n-coins[i]>=0){
		int subprob=mincoins(n-coins[i],coins, t,dp)+1;

		ans=min(ans,subprob);
		}
	}
	dp[n]=ans;
	return ans;


}

// Bottom up approach 
int mincoins2(int n,int coins[],int t){

int dp[1000]={0};

for(int j=1;j<=n;j++){


	dp[j]=INT_MAX;
	for(int i=0;i<t;i++){

		if(j-coins[i]>=0){
		int subprob=dp[j-coins[i]]+1;

		dp[j]=min(dp[j],subprob);
		
		}
	}
 
	


}

return dp[n];

}





int main(){
int dp[1000]={0};
int coins[] = {1, 7, 10};
int t=sizeof(coins)/sizeof(coins[0]);
cout<<mincoins(15,coins,t,dp)<<endl;

cout<<mincoins2(15,coins,t);






}