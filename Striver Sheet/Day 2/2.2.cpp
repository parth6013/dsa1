// pascal triangle


// brute logical approach is best based upon the fact that there will be 1's at the end and middle elements will be sum of
// above column and one preecedding it




#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> generate(int numRows) {
	vector<vector<int>> ret;
	for (int i = 0; i < numRows; i++) {
		vector<int> row(i + 1, 1);
		for (int j = 1; j < i; j++) {
			row[j] = ret[i - 1][j] + ret[i - 1][j - 1];
		}
		ret.push_back(row);
	}
	return ret;
}




// ncr method
    int fact(int n){
        if(n==0 || n==1){
            return 1;
        }
        
        return  n*fact(n-1);
    }
    
    
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(100,vector<int>(100,0));
        
        for(int i=0;i<numRows;i++){
            for(int j=0;j<=i;j++){
                // cout<<i<<j;
                ans[i][j]= fact(i)/(fact(i-j)*fact(j));
            }
        }
        
        return ans;
    }

int main(){

    vector<vector<int>> x;

    x=generate(5);

    for(int i=0;i<5;i++){
        for(int j=0;j<=i;j++){
            cout<<x[i][j]<<" ";
        }
        cout<<endl;
    }

}