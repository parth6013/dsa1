// USING PRECOMPUTING

#include<iostream>
using namespace std;

int main(){
    
    int n;
    cin>>n;
    
    int a[n];

    int currentSum=0;
    int maximumSum=0;
    int cumSum[1000]={0};

    int left=-1;
    int right=-1;
    
    
    cin>>a[0];
    cumSum[0]=a[0];
    
    for(int i=1;i<n;i++){
        cin>>a[i];
        cumSum[i]= cumSum[i-1]+a[i];
    }
    
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            currentSum=0;

            currentSum =cumSum[j]-cumSum[i-1];
            // cout<<cumSum[j]<<"**"<<j<<"###"<<cumSum[i-1]<<"**"<<i<<endl; 
            if(currentSum>maximumSum){
                left=i;
                right=j;
                maximumSum=currentSum;
            }
        }
    }
    cout<<cumSum[-1];
    cout<<maximumSum<<endl;
    for(int i=left;i<=right;i++){
        cout<<a[i]<<" ";
    }

}