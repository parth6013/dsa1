// maximum jobs
// sort the array accordig to profit then we do the most profitable job on its last day possible
// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/
bool compare(Job ob1,Job ob2){
    return( ob1.profit>ob2.profit);
}
class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        vector<int> v;
        int maxi=arr[0].dead;
        for(int i=0;i<n;i++){
            maxi=max(maxi,arr[i].dead);
        }
        
        sort(arr,arr+n,compare);
        
        int cnt=0;
        int profit=0;
        
        int store[maxi+1];
        
        for(int i=0;i<=maxi+1;i++){
            store[i]=-1;
        }
        
        for(int i=0;i<n;i++){
            for(int j=arr[i].dead;j>=1;j--){
                if(store[j]==-1){
                    store[j]=arr[i].id;
                    cnt++;
                    profit+=arr[i].profit;
                    break;
                }
            }
        }
        
        v.push_back(cnt);
        v.push_back(profit);
        
        
        
        return v;
        
        
        // your code here
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends