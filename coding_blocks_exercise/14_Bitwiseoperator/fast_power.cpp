#include<iostream>
using namespace std;
// it works in logk time instead of k
int power_optimised(int n,int p){

    int ans=1;

    int f=0;
    while(p>0){

        f=1;
        cout<<"#";
        int a1;
        a1=p&1;
        

        if(a1==1){
            ans=ans * n;
            n=n*n;

        }
        else{
            n=n*n;
        }
        p=p>>1;


    }

    if(f==1){
        return ans;
    }
    else{
        return 0;
    }

    }

int main(){

    int n=power_optimised(2,7);
    cout<<n;
    

    

}