// Fractional knapsack

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/
bool compare(Item a1,Item a2){
    double x1=(double)a1.value/(double)a1.weight;
    double x2=(double)a2.value/(double)a2.weight;
    
    return (x1>x2);
}

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        
        sort(arr,arr+n,compare);
        
        // for(int i=0;i<n;i++){
        //     // cout<<arr[i].value<<arr[i].weight<<endl;
        // }
        double price=0;
        int i=0;
        while(W!=0 && i<n){
            if(arr[i].weight<=W){
                W=W-arr[i].weight;
                price=price+arr[i].value;
            }else{
                double x;
                x=(double)arr[i].value/(double)arr[i].weight;
                price=price+(W*x);
                W=0;
            }
            i++;
        }
        
        return price;
        
        // Your code here
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends