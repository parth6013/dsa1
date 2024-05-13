// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:

    void print_sum(vector<int> arr, int i ,int N,int sum1,vector<int> &ans){
        if(i==N){
            // cout<<sum1<<" ";
            ans.push_back(sum1);
            return;
        }
        
        // Don't take that element
        print_sum(arr,i+1,N,sum1,ans);
        
        // take that element
        sum1=sum1+arr[i];
        print_sum(arr,i+1,N,sum1,ans);
    }
    

    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        print_sum(arr,0,N,0,ans);
        sort(ans.begin(),ans.end());
        
        return ans;
        // Write Your Code here
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends