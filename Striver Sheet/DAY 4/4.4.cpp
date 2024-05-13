// longest sub array with sun 0


// brute force ,O(n^2) compute subarray sum, maintain max lenth

// Optimized version maintain prefix sum ,if 0 then maintain leth , or if prefix sum repeats means it has been 0 in between
// so minus the indexes
// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        int ans=0;
        int s1=0;
        
        unordered_map<int,int> mpp;
        
        for(int i=0;i<n;i++){
            
            s1=s1+A[i];
            
            if(s1==0){
                ans=max(ans,i+1);
            }
            auto it=mpp.find(s1);
            if(it!=mpp.end()){
                ans=max(ans,i-(it->second));
            }else{
                mpp[s1]=i;
            }
            
        }
        
        return ans;
        
        
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends